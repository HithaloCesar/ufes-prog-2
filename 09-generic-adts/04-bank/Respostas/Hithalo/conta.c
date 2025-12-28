#include "conta.h"
#include <stdlib.h>
#include <stdio.h>

struct Conta {
    int numero;
    char *nomeCliente;
    float saldo;
};

tConta *CriaConta(void) {
    tConta *conta = calloc(1, sizeof(*conta));

    return conta;
}

void DestroiConta(DataType conta) {
    tConta *c = (tConta *)conta;
    free(c->nomeCliente);
    free(c);
}

void LeConta(tConta *conta) {
    scanf("%d;%m[^;];%f", &conta->numero, &conta->nomeCliente, &conta->saldo);
    getchar();
}

float GetSaldoConta(tConta *conta) {
    return conta->saldo;
}
