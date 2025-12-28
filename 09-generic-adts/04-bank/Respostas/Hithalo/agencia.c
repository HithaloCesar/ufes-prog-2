#include "agencia.h"
#include <stdlib.h>
#include <stdio.h>

struct Agencia {
    int numero;
    char *nome;
    Vector *contas;
};

tAgencia *CriaAgencia(void) {
    tAgencia *agencia = calloc(1, sizeof(*agencia));

    agencia->contas = VectorConstruct();

    return agencia;
}

void DestroiAgencia(DataType agencia) {
    tAgencia *a = (tAgencia *)agencia;
    free(a->nome);
    VectorDestroy(a->contas, DestroiConta);
    free(a);
}

void LeAgencia(tAgencia *agencia) {
    scanf("%d;%m[^\n]", &agencia->numero, &agencia->nome);
    getchar();
}

void AdicionaConta(tAgencia *agencia, tConta *conta) {
    VectorPushBack(agencia->contas, conta);
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2) {
    return numAgencia == agencia2->numero;
}

float GetSaldoMedioAgencia (tAgencia *agencia) {
    float numContas = VectorSize(agencia->contas);

    float somaSaldos = 0;
    for (int i = 0; i < numContas; i++) {
        tConta *conta = VectorGet(agencia->contas, i);
        float saldo = GetSaldoConta(conta);
        somaSaldos += saldo;
    }

    float mediaSaldos = somaSaldos / numContas;

    return mediaSaldos;
}

void ImprimeDadosAgencia(tAgencia *agencia) {
    int numContas = VectorSize(agencia->contas);
    float mediaSaldos = GetSaldoMedioAgencia(agencia);

    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->numero);
    printf("\tNumero de contas cadastradas: %d\n", numContas);
    printf("\tSaldo médio: R$%.2f\n", mediaSaldos);
}
