#include <stdlib.h>
#include <stdio.h>

int *CriaVetor(int tamanho) {
    int *v = malloc(tamanho * sizeof(*v));

    if (v == NULL) {
        return NULL;
    }

    return v;
}

void LeVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return (float)soma / tamanho;
}

void LiberaVetor(int *vetor) {
    free(vetor);
}
