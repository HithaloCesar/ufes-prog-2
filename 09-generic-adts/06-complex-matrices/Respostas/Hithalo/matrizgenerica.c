#include "matrizgenerica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct matrizgenerica {
    void **elementos;
    int qtdLinhas;
    int qtdColunas;
    int numByteElem;
};

tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem) {
    tMatrizGenerica *mat = calloc(1, sizeof(*mat));

    mat->elementos = calloc(linhas, sizeof(*mat->elementos));
    for (int i = 0; i < linhas; i++) {
        mat->elementos[i] = calloc(colunas, numByteElem);
    }

    mat->qtdColunas = colunas;
    mat->qtdLinhas = linhas;
    mat->numByteElem = numByteElem;

    return mat;
}

void DestroiMatrizGenerica(tMatrizGenerica *mat) {
    for (int i = 0; i < mat->qtdLinhas; i++) {
        free(mat->elementos[i]);
    }
    free(mat->elementos);
    free(mat);
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat) {
    return mat->qtdLinhas;
}

int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat) {
    return mat->qtdColunas;
}

void *ObtemElementoMatrizGenerica(
    tMatrizGenerica *mat,
    int linha,
    int coluna
) {
    return (char *)mat->elementos[linha] + coluna * mat->numByteElem;
}

void AtribuiElementoMatrizGenerica(
    tMatrizGenerica *mat,
    int linha,
    int coluna,
    void *elem
) {
    void *dest = ObtemElementoMatrizGenerica(mat, linha, coluna);
    memcpy(dest, elem, mat->numByteElem);
}

void ImprimirMatrizGenerica(
    tMatrizGenerica *mat,
    void (imprime_elemento(void *))
) {
    for (int i = 0; i < mat->qtdLinhas; i++) {
        char *sep = "";
        for (int j = 0; j < mat->qtdColunas; j++) {
            printf("%s", sep);
            imprime_elemento(ObtemElementoMatrizGenerica(mat, i, j));
            sep = " ";
        }
        putchar('\n');
    }
}

tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat) {
    tMatrizGenerica *transp = CriaMatrizGenerica(
        mat->qtdColunas,
        mat->qtdLinhas,
        mat->numByteElem
    );

    for (int i = 0; i < mat->qtdLinhas; i++) {
        for (int j = 0; j < mat->qtdColunas; j++) {
            void *src = ObtemElementoMatrizGenerica(mat, i, j);
            void *dest = ObtemElementoMatrizGenerica(transp, j, i);
            memcpy(dest, src, mat->numByteElem);
        }
    }

    return transp;
}

tMatrizGenerica *MultiplicaMatrizes(
    tMatrizGenerica *mat1,
    tMatrizGenerica *mat2,
    int numByteTarget,
    void *(*multi_elem)(void *, void *),
    void *(*soma_elem)(void *,void *)
) {
    tMatrizGenerica *prod = CriaMatrizGenerica(
        mat1->qtdLinhas, mat2->qtdColunas, numByteTarget
    );

    for (int i = 0; i < mat1->qtdLinhas; i++) {
        for (int j = 0; j < mat2->qtdColunas; j++) {
            void *dest = ObtemElementoMatrizGenerica(prod, i, j);
            for (int k = 0; k < mat1->qtdColunas; k++) {
                void *dado1 = ObtemElementoMatrizGenerica(mat1, i, k);
                void *dado2 = ObtemElementoMatrizGenerica(mat2, k, j);
                void *prodTemp = multi_elem(dado1, dado2);
                if (k == 0) {
                    memcpy(dest, prodTemp, numByteTarget);
                } else {
                    void *somaTemp = soma_elem(dest, prodTemp);
                    memcpy(dest, somaTemp, numByteTarget);
                    free(somaTemp);
                }
                free(prodTemp);
            }
        }
    }

    return prod;
}

tMatrizGenerica *ConverteTipoMatriz(
    tMatrizGenerica *mat,
    int novoNumByteElem,
    void *(*converte_elem)(void *)
) {
    tMatrizGenerica *nova = CriaMatrizGenerica(
        mat->qtdLinhas, mat->qtdColunas, novoNumByteElem
    );

    for (int i = 0; i < mat->qtdLinhas; i++) {
        for (int j = 0; j < mat->qtdColunas; j++) {
            void *src = ObtemElementoMatrizGenerica(mat, i, j);
            void *dest = ObtemElementoMatrizGenerica(nova, i, j);
            void *dadoConvertido = converte_elem(src);
            memcpy(dest, dadoConvertido, novoNumByteElem);
            free(dadoConvertido);
        }
    }

    return nova;
}
