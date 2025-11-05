#include "vetor.h"
#include <stdio.h>

void LeVetor(Vetor *vetor) {
    int tamanho;
    scanf("%d", &tamanho);

    vetor->tamanhoUtilizado = 0;
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor->elementos[i]);
        vetor->tamanhoUtilizado++;
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    int resultado = vetor->elementos[0];

    for (int i = 1; i < vetor->tamanhoUtilizado; i++) {
        resultado = op(vetor->elementos[i], resultado);
    }

    return resultado;
}
