#include "agencia.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "operacao.h"

#define MINIMO_OPERACAO_SUSPEITA 20000

struct Agencia {
    tConta **contas;
    int qtdContas;
    int maxContas;

    tOperacao **operacoes;
    int qtdOperacoes;
    int maxOperacoes;
};

static int ComparaSaldoConta(const void *a, const void *b);

tAgencia *CriaAgencia(void) {
    tAgencia *agencia = calloc(1, sizeof(*agencia));

    return agencia;
}

void DestroiAgencia(tAgencia *agencia) {
    for (int i = 0; i < agencia->qtdContas; i++) {
        DestroiConta(agencia->contas[i]);
    }
    free(agencia->contas);

    for (int i = 0; i < agencia->qtdOperacoes; i++) {
        DestroiOperacao(agencia->operacoes[i]);
    }
    free(agencia->operacoes);

    free(agencia);
}

void LeOperacoes(tAgencia *agencia) {
    putchar('\n');

    int qtdContas;
    scanf("%d", &qtdContas);
    getchar();

    agencia->contas = calloc(qtdContas, sizeof(*agencia->contas));

    for (int i = 0; i < qtdContas; i++) {
        int id;
        bool leituraOk = false;
        while (!leituraOk) {
            scanf("%d", &id);
            getchar();

            if (id < 0) {
                puts("Digite um id valido para a conta a ser cadastrada!");
                continue;
            };
            if (BuscaContaPorId(agencia, id) != NULL) {
                puts("Este id ja esta cadastrado na agencia. Digite um id diferente!");
                continue;
            }

            leituraOk = true;
        }

        agencia->contas[agencia->qtdContas++] = CriaConta(id);
    }

    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);
    getchar();

    agencia->operacoes = calloc(qtdOperacoes, sizeof(*agencia->operacoes));

    for (int i = 0; i < qtdOperacoes; i++) {
        int id;
        float valor;
        tConta *conta;

        bool leituraOk = false;
        while (!leituraOk) {
            scanf("%d %f", &id, &valor);
            getchar();

            conta = BuscaContaPorId(agencia, id);
            if (conta == NULL) {
                puts("Conta Invalida! Repita a operacao, mas com uma conta valida!");
                continue;
            }

            leituraOk = true;
        }

        tOperacao *op = CriaOperacao(conta, valor);
        agencia->operacoes[agencia->qtdOperacoes++] = op;
        AlteraSaldoConta(conta, ConsultaValorOperacao(op));
    }
}

tConta *BuscaContaPorId(tAgencia *agencia, int id) {
    for (int i = 0; i < agencia->qtdContas; i++) {
        if (ConfereIdConta(agencia->contas[i], id)) {
            return agencia->contas[i];
        }
    }

    return NULL;
}

void ImprimeOperacoesSuspeitas(tAgencia *agencia) {
    puts("A lista de operações suspeitas:");

    for (int i = 0; i < agencia->qtdOperacoes; i++) {
        float valor = ConsultaValorOperacao(agencia->operacoes[i]);
        if (fabs(valor) > MINIMO_OPERACAO_SUSPEITA) {
            ImprimeOperacao(agencia->operacoes[i]);
        }
    }
}

void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia *agencia) {
    qsort(
        agencia->contas,
        agencia->qtdContas,
        sizeof(*agencia->contas),
        ComparaSaldoConta
    );

    putchar('\n');

    puts("Os dois correntistas com maior saldo são:");

    printf(
        "Id: %d, Saldo: %.2f\n",
        RetornaIdConta(agencia->contas[0]),
        RetornaSaldoConta(agencia->contas[0])
    );

    printf(
        "Id: %d, Saldo: %.2f\n",
        RetornaIdConta(agencia->contas[1]),
        RetornaSaldoConta(agencia->contas[1])
    );
}

void ImprimeSaldoTotal(tAgencia *agencia) {
    float saldo = 0;
    for (int i = 0; i < agencia->qtdContas; i++) {
        saldo += RetornaSaldoConta(agencia->contas[i]);
    }

    printf("O saldo total da agencia eh: %.2f\n", saldo);
}

static int ComparaSaldoConta(const void *a, const void *b) {
    tConta *conta1 = *(tConta**)a;
    tConta *conta2 = *(tConta**)b;

    return RetornaSaldoConta(conta2) - RetornaSaldoConta(conta1);
}
