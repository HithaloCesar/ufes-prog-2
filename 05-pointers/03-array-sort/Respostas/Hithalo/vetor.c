#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int *n, int tam) {
    const char *sep = "";
    for (int i = 0; i < tam; i++) {
        printf("%s%d", sep, n[i]);
        sep = " ";
    }
    putchar('\n');
}

void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar) {
    int indiceDoMenor = 0;
    for (int i = 1; i < tam; i++) {
        if (vet[i] < vet[indiceDoMenor]) {
            indiceDoMenor = i;
        }
    }

    if (vet[indiceDoMenor] < *paraTrocar) {
        int temp = vet[indiceDoMenor];
        vet[indiceDoMenor] = *paraTrocar;
        *paraTrocar = temp;
    }
}

void OrdeneCrescente(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        TrocaSeAcharMenor(vet + i, tam - i, &vet[i]);
    }
}
