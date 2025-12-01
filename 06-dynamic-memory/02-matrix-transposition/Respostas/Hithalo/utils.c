#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int **CriaMatriz(int linhas, int colunas) {
    int **matriz = malloc(linhas * sizeof(*matriz));

    if (matriz == NULL) {
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(*matriz[i]));

        if (matriz[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free (matriz);
            return NULL;
        }
    }

    return matriz;
}

void LiberaMatriz(int **matriz, int linhas) {
    if (matriz == NULL) {
        return;
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas) {
    for (int j = 0; j < colunas; j++) {
        const char *sep = "";
        for (int i = 0; i < linhas; i++) {
            printf("%s%d", sep, matriz[i][j]);
            sep = " ";
        }
        putchar('\n');
    }
}
