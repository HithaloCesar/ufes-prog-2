#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "loja.h"

typedef enum {
    OPERACAO_ENCERRAR,
    OPERACAO_ABRIR_LOJA,
    OPERACAO_CONTRATAR_VENDEDOR,
    OPERACAO_REGISTRAR_VENDA
} tOperacao;

int main(void) {
    int maxLojas;
    scanf("%d", &maxLojas);
    getchar();

    tLoja **lojas = calloc(maxLojas, sizeof(*lojas));
    int qtdLojas = 0;

    bool continuarExecucao = true;
    while (continuarExecucao) {
        int opcao;
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case OPERACAO_ABRIR_LOJA: {
                int id;
                float aluguel;
                scanf("%d %f", &id, &aluguel);
                getchar();
                lojas[qtdLojas++] = AbreLoja(id, aluguel);
                break;
            }
            case OPERACAO_CONTRATAR_VENDEDOR: {
                char *nome;
                float salario, prct_comissao;
                scanf(" %ms %f %f", &nome, &salario, &prct_comissao);
                getchar();
                tVendedor *v = RegistraVendedor(nome, salario, prct_comissao);
                int id;
                scanf("%d", &id);
                getchar();
                for (int i = 0; i < qtdLojas; i++) {
                    if (VerificaIdLoja(lojas[i], id)) {
                        ContrataVendedor(lojas[i], v);
                        break;
                    }
                }
                free(nome);
                break;
            }
            case OPERACAO_REGISTRAR_VENDA: {
                int id;
                char *nome;
                float valor;
                scanf("%d %ms %f", &id, &nome, &valor);
                getchar();
                for (int i = 0; i < qtdLojas; i++) {
                    if (VerificaIdLoja(lojas[i], id)) {
                        RegistraVenda(lojas[i], nome, valor);
                    }
                }
                free(nome);
                break;
            }
            case OPERACAO_ENCERRAR: {
                continuarExecucao = false;
                break;
            }
        }
    }

    for (int i = 0; i < qtdLojas; i++) {
        CalculaLucro(lojas[i]);
        ImprimeRelatorioLoja(lojas[i]);
    }

    for (int i = 0; i < qtdLojas; i++) {
        ApagaLoja(lojas[i]);
    }
    free(lojas);

    return EXIT_SUCCESS;
}
