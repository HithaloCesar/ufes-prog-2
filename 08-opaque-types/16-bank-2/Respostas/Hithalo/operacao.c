#include "operacao.h"
#include <stdlib.h>
#include <stdio.h>

struct Operacao {
    tConta *conta;
    float valor;
};

tOperacao *CriaOperacao(tConta *conta, float valor) {
    tOperacao *op = calloc(1, sizeof(*op));

    op->conta = conta;
    op->valor = valor;

    return op;
}

void DestroiOperacao(tOperacao *op) {
    free(op);
}

float ConsultaValorOperacao(tOperacao *op) {
    return op->valor;
}

void ImprimeOperacao(tOperacao *op) {
    putchar('\n');

    int id = RetornaIdConta(op->conta);
    printf("Operação na conta %d com valor %.2f\n", id, op->valor);
}
