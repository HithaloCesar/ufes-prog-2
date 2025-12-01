#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(void) {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    int **matriz = CriaMatriz(linhas, colunas);

    if (matriz == NULL) {
        fprintf(stderr, "ERROR: The memory could not be written.\n");
        return EXIT_FAILURE;
    }

    LeMatriz(matriz, linhas, colunas);

    ImprimeMatrizTransposta(matriz, linhas, colunas);

    LiberaMatriz(matriz, linhas);

    return EXIT_SUCCESS;
}
