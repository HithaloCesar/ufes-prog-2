#include <stdlib.h>
#include <stdio.h>
#include "vetor.h"

#define MAX_SIZE_ARRAY 1024

int main(void) {
    int casos;
    scanf("%d", &casos);

    for (int i = 0; i < casos; i++) {
        int tam;
        scanf("%d", &tam);

        if (tam > MAX_SIZE_ARRAY) {
            return EXIT_FAILURE;
        }

        int vet[MAX_SIZE_ARRAY];
        LeDadosParaVetor(vet, tam);

        OrdeneCrescente(vet, tam);

        ImprimeDadosDoVetor(vet, tam);
    }

    return EXIT_SUCCESS;
}
