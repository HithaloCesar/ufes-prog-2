#include "banco.h"
#include <stdlib.h>
#include <stdio.h>

#define CONTAS_TAM_INICIAL 16

static tConta *BuscaConta(
    tConta **contas,
    int qtdContas,
    int numeroConta
);

tBanco *CriaBanco(void) {
    tBanco *banco = calloc(1, sizeof(*banco));

    return banco;
}

void DestroiBanco(tBanco *banco) {
    for (int i = 0; i < banco->qtdContas; i++) {
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);

    free(banco);
}

void AbreContaBanco(tBanco *banco) {
    if (banco->qtdContas == banco->contasAlocadas) {
        if (banco->contasAlocadas == 0) {
            banco->contasAlocadas = CONTAS_TAM_INICIAL;
        } else {
            banco->contasAlocadas *= 2;
        }

        banco->contas = realloc(
            banco->contas, banco->contasAlocadas * sizeof(*banco->contas)
        );
    }

    tConta *conta = CriaConta();
    LeConta(conta);

    banco->contas[banco->qtdContas++] = conta;
}

void SaqueContaBanco(tBanco *banco) {
    int numeroConta;
    float valor;
    scanf("%d %f", &numeroConta, &valor);
    getchar();

    tConta *conta = BuscaConta(
        banco->contas,
        banco->qtdContas,
        numeroConta
    );

    SaqueConta(conta, valor);
}

void DepositoContaBanco(tBanco *banco) {
    int numeroConta;
    float valor;
    scanf("%d %f", &numeroConta, &valor);
    getchar();

    tConta *conta = BuscaConta(
        banco->contas,
        banco->qtdContas,
        numeroConta
    );

    DepositoConta(conta, valor);
}

void TransferenciaContaBanco(tBanco *banco) {
    int numeroContaOrigem, numeroContaDestino;
    float valor;
    scanf("%d %d %f", &numeroContaDestino, &numeroContaOrigem, &valor);
    getchar();

    tConta *contaOrigem = BuscaConta(
        banco->contas,
        banco->qtdContas,
        numeroContaOrigem
    );

    tConta *contaDestino = BuscaConta(
        banco->contas,
        banco->qtdContas,
        numeroContaDestino
    );

    TransferenciaConta(contaDestino, contaOrigem, valor);
}

void ImprimeRelatorioBanco(tBanco *banco) {
    printf("===| Imprimindo Relatorio |===\n");

    for (int i = 0; i < banco->qtdContas; i++) {
        ImprimeConta(banco->contas[i]);
        putchar('\n');
    }
}

static tConta *BuscaConta(
    tConta **contas,
    int qtdContas,
    int numeroConta
) {
    for (int i = 0; i < qtdContas; i++) {
        if (VerificaConta(contas[i], numeroConta)) {
            return contas[i];
        }
    }

    return NULL;
}
