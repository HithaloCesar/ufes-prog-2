#include "conta.h"
#include <stdlib.h>
#include <stdio.h>

tConta *CriaConta(void) {
    tConta *conta = calloc(1, sizeof(*conta));

    conta->user = CriaUsuario();

    return conta;
}

void DestroiConta(tConta *conta) {
    if (conta->user) {
        DestroiUsuario(conta->user);
    }

    free(conta);
}

void LeConta(tConta *conta) {
    LeUsuario(conta->user);
    scanf("%d", &conta->numero);
    getchar();
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero) {
    return conta->numero == numero;
}

void SaqueConta(tConta *conta, float valor) {
    if (conta->saldo < valor) {
        return;
    }

    conta->saldo -= valor;
}

void DepositoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    if (origem->saldo < valor) {
        return;
    }

    SaqueConta(origem, valor);
    DepositoConta(destino, valor);
}
