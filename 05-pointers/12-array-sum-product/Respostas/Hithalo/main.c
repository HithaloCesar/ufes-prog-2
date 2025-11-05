#include <stdlib.h>
#include <stdio.h>
#include "vetor.h"

static int adicao(int n1, int n2);

static int multiplicacao(int n1, int n2);

int main(void) {
    Vetor vetor;
    LeVetor(&vetor);

    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, adicao));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, multiplicacao));

    return EXIT_SUCCESS;
}

static int adicao(int n1, int n2) {
    return n1 + n2;
}

static int multiplicacao(int n1, int n2) {
    return n1 * n2;
}
