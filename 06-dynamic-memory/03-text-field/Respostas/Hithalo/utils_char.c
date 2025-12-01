#include "utils_char.h"
#include <stdlib.h>
#include <stdio.h>

char *CriaVetor(int tamanho) {
    char *vetor = malloc(tamanho * sizeof(*vetor));

    if (vetor == NULL) {
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = '_';
    }

    return vetor;
}

void LeVetor(char *vetor, int tamanho) {
    char c;
    for (int i = 0; (c = getchar()) != '\n' && i < tamanho; i++) {
        vetor[i] = c;
    }
}

void ImprimeString(char *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        putchar(vetor[i]);
    }
    putchar('\n');
}

void LiberaVetor(char *vetor) {
    free(vetor);
}
