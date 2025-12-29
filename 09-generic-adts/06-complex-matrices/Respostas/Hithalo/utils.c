#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"

static bool ValidaTipo(int tipo);
static bool ValidaOpcaoMatriz(int opcao);
static bool ValidaOpcaoPrograma(int opcao);
static void *MultComplexosWrapper(void *n1, void *n2);
static void *SomaComplexosWrapper(void *n1, void *n2);
static void ImprimeNumeroComplexoWrapper(void *n);
static void LeMatrizGenerica(
    tMatrizGenerica *matriz,
    void *(*LeElemento)(void),
    void (*DestroiElemento)(void *)
);
static void *LeInt(void);
static void ImprimeInt(void *n);
static void *LeFloat(void);
static void ImprimeFloat(void *n);
static void *LeDouble(void);
static void ImprimeDouble(void *n);
static void *LeChar(void);
static void ImprimeChar(void *c);
static void DestroiSimples(void *n);
static void *LeComplexo(void);
static void *ConverteIntParaComplexo(void *n);
static void *ConverteFloatParaComplexo(void *n);
static void *ConverteDoubleParaComplexo(void *n);
static void *ConverteCharParaComplexo(void *n);
static tMatrizGenerica *ConverteMatGenParaComplexo(
    tMatrizGenerica *m,
    int tipo
);
static tMatrizGenerica *ImprimeMatGenPorTipo(
    tMatrizGenerica *matriz,
    int tipo
);

void LeConfiguracao(int *linhas, int *colunas, int *tipo) {
    while (true) {
        fputs("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo):", stdout);
        // Sem '\n'... Ok...? E esses hífens Unicode...?

        scanf("%d %d %d", linhas, colunas, tipo);
        getchar();
        if (ValidaTipo(*tipo)) {
            break;
        }
    }
    putchar('\n');
}

int LeOpcaoMatriz(void) {
    int opcao;
    while (true) {
        puts("Digite a operação desejada");
        puts("\t1 - Apenas imprimir a matriz");
        puts("\t2 - Converter para o tipo complexo e imprimir");
        puts("\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.");
        // Opção 3 na verdade exige a conversão para complexo primeiro...

        scanf("%d", &opcao);
        getchar();
        if (ValidaOpcaoMatriz(opcao)) {
            return opcao;
        }
    }
}

int LeOpcaoPrograma(void) {
    int opcao;
    while (true) {
        puts("Digite a operação desejada");
        puts("\t1 - Entrar com uma nova matriz");
        puts("\t2 - Encerrar o Programa");

        scanf("%d", &opcao);
        getchar();
        if (ValidaOpcaoPrograma(opcao)) {
            return opcao;
        }
    }
}

tMatrizGenerica *CriaLeMatriz(int linhas, int colunas, int tipo) {
    tMatrizGenerica *m;
    switch (tipo) {
        case TIPO_INT: {
            m = CriaMatrizGenerica(linhas, colunas, sizeof(int));
            LeMatrizGenerica(m, LeInt, DestroiSimples);
            break;
        }
        case TIPO_FLOAT: {
            m = CriaMatrizGenerica(linhas, colunas, sizeof(float));
            LeMatrizGenerica(m, LeFloat, DestroiSimples);
            break;
        }
        case TIPO_DOUBLE: {
            m = CriaMatrizGenerica(linhas, colunas, sizeof(double));
            LeMatrizGenerica(m, LeDouble, DestroiSimples);
            break;
        }
        case TIPO_CHAR: {
            m = CriaMatrizGenerica(linhas, colunas, sizeof(char));
            LeMatrizGenerica(m, LeChar, DestroiSimples);
            break;
        }
        case TIPO_COMPLEXO: {
            m = CriaMatrizGenerica(linhas, colunas, RetornaNumBytesComplexo());
            LeMatrizGenerica(m, LeComplexo, DestroiSimples);
            break;
        }
    }

    return m;
}

void AcaoImprime(tMatrizGenerica *m, int tipo) {
    ImprimeMatGenPorTipo(m, tipo);
}

void AcaoConverteImprime(tMatrizGenerica *m, int tipo) {
    tMatrizGenerica *mCplx = ConverteMatGenParaComplexo(m, tipo);
    ImprimirMatrizGenerica(mCplx, ImprimeNumeroComplexoWrapper);
    if (m != mCplx) {
        DestroiMatrizGenerica(mCplx);
    }
}

void AcaoConverteMultiplicaTranspostaImprime(tMatrizGenerica *m, int tipo) {
    int bytesCplx = RetornaNumBytesComplexo();

    tMatrizGenerica *mCplx = ConverteMatGenParaComplexo(m, tipo);
    tMatrizGenerica *transpCplx = MatrizTransposta(mCplx);
    tMatrizGenerica *produto = MultiplicaMatrizes(
        mCplx,
        transpCplx,
        bytesCplx,
        MultComplexosWrapper,
        SomaComplexosWrapper
    );

    ImprimirMatrizGenerica(produto, ImprimeNumeroComplexoWrapper);

    if (m != mCplx) {
        DestroiMatrizGenerica(mCplx);
    }
    DestroiMatrizGenerica(transpCplx);
    DestroiMatrizGenerica(produto);
}

static bool ValidaTipo(int tipo) {
    switch (tipo) {
        case TIPO_INT:
        case TIPO_FLOAT:
        case TIPO_DOUBLE:
        case TIPO_CHAR:
        case TIPO_COMPLEXO:
            return true;
        default:
            return false;
    }
}

static bool ValidaOpcaoMatriz(int opcao) {
    switch (opcao) {
        case OPCAO_MATRIZ_IMPRIMIR:
        case OPCAO_MATRIZ_CONV_COMPLEXO_IMPRIMIR:
        case OPCAO_MATRIZ_CONV_COMPLEXO_MULT_TRANSPOSTA:
            return true;
        default:
            return false;
    }
}

static bool ValidaOpcaoPrograma(int opcao) {
    switch (opcao) {
        case OPCAO_PROGRAMA_CONTINUAR:
        case OPCAO_PROGRAMA_FINALIZAR:
            return true;
        default:
            return false;
    }
}

static void *MultComplexosWrapper(void *n1, void *n2) {
    return (void *)MultComplexos((tNumComplexo *)n1, (tNumComplexo *)n2);
}

static void *SomaComplexosWrapper(void *n1, void *n2) {
    return (void *)SomaComplexos((tNumComplexo *)n1, (tNumComplexo *)n2);
}

static void ImprimeNumeroComplexoWrapper(void *n) {
    ImprimeNumeroComplexo((tNumComplexo *)n);
}

static void LeMatrizGenerica(
    tMatrizGenerica *matriz,
    void *(*LeElemento)(void),
    void (*DestroiElemento)(void *)
) {
    int linhas = ObtemNumeroLinhasMatrizGenerica(matriz);
    int colunas = ObtemNumeroColunasMatrizGenerica(matriz);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            void *elemento = LeElemento();
            AtribuiElementoMatrizGenerica(matriz, i, j, elemento);
            DestroiElemento(elemento);
        }
    }
}

static void *LeInt(void) {
    int *n = malloc(sizeof(*n));
    scanf("%d", n);
    getchar();
    return n;
}

static void ImprimeInt(void *n) {
    printf("%d", *((int *)n));
}

static void *LeFloat(void) {
    float *n = malloc(sizeof(*n));
    scanf("%f", n);
    getchar();
    return n;
}

static void ImprimeFloat(void *n) {
    printf("%.2f", *((float *)n));
}

static void *LeDouble(void) {
    double *n = malloc(sizeof(*n));
    scanf("%lf", n);
    getchar();
    return n;
}

static void ImprimeDouble(void *n) {
    printf("%.2f", *((double *)n));
}

static void *LeChar(void) {
    char *c = malloc(sizeof(*c));
    scanf(" %c", c);
    return c;
}

static void ImprimeChar(void *c) {
    printf("%c", *((char *)c));
}

static void DestroiSimples(void *n) {
    free(n);
}

static void *LeComplexo(void) {
    float real, imag;
    scanf(" (%f,%f)", &real, &imag);
    getchar();
    tNumComplexo *cplx = CriaNumComplexo(real, imag);
    return cplx;
}

static void *ConverteIntParaComplexo(void *n) {
    int i = *((int *)n);
    tNumComplexo *cplx = CriaNumComplexo(i, 0);
    return cplx;
}

static void *ConverteFloatParaComplexo(void *n) {
    float f = *((float *)n);
    tNumComplexo *cplx = CriaNumComplexo(f, 0);
    return cplx;
}

static void *ConverteDoubleParaComplexo(void *n) {
    double d = *((double *)n);
    tNumComplexo *cplx = CriaNumComplexo(d, 0);
    return cplx;
}

static void *ConverteCharParaComplexo(void *n) {
    char c = *((char *)n);
    c -= '0';
    tNumComplexo *cplx = CriaNumComplexo(c, 0);
    return cplx;
}

static tMatrizGenerica *ConverteMatGenParaComplexo(
    tMatrizGenerica *m,
    int tipo
) {
    int bytesCplx = RetornaNumBytesComplexo();
    tMatrizGenerica *convertida;
    switch (tipo) {
        case 0: {
            convertida = ConverteTipoMatriz(
                m, bytesCplx, ConverteIntParaComplexo
            );
            break;
        }
        case 1: {
            convertida = ConverteTipoMatriz(
                m, bytesCplx, ConverteFloatParaComplexo
            );
            break;
        }
        case 2: {
            convertida = ConverteTipoMatriz(
                m, bytesCplx, ConverteDoubleParaComplexo
            );
            break;
        }
        case 3: {
            convertida = ConverteTipoMatriz(
                m, bytesCplx, ConverteCharParaComplexo
            );
            break;
        }
        case 4: {
            convertida = m;
            break;
        }
    }

    return convertida;
}

static tMatrizGenerica *ImprimeMatGenPorTipo(
    tMatrizGenerica *matriz,
    int tipo
) {
    switch (tipo) {
        case 0: {
            ImprimirMatrizGenerica(matriz, ImprimeInt);
            break;
        }
        case 1: {
            ImprimirMatrizGenerica(matriz, ImprimeFloat);
            break;
        }
        case 2: {
            ImprimirMatrizGenerica(matriz, ImprimeDouble);
            break;
        }
        case 3: {
            ImprimirMatrizGenerica(matriz, ImprimeChar);
            break;
        }
        case 4: {
            ImprimirMatrizGenerica(matriz, ImprimeNumeroComplexoWrapper);
            break;
        }
    }
}
