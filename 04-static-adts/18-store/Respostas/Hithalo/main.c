#include <stdlib.h>
#include <stdio.h>
#include "store.h"

typedef enum {
    OPERACAO_CADASTRAR = 'C',
    OPERACAO_ESTOCAR = 'E',
    OPERACAO_VENDER = 'V',
    OPERACAO_DESCONTO = 'D',
    OPERACAO_INVENTARIO = 'I',
    OPERACAO_RELATORIO = 'R',
    OPERACAO_FINALIZAR = 'F'
} tOperacao;

static void imprimeMenu(void);

int main(void) {
    tStore loja = abreLoja();

    imprimeMenu();

    char operacao;
    while (scanf("%c\n", &operacao) == 1 && operacao != OPERACAO_FINALIZAR) {
        switch (operacao) {
            case OPERACAO_CADASTRAR: {
                loja = adicionaProduto(loja, leProduto());
                break;
            }

            case OPERACAO_ESTOCAR: {
                int id, qtd;

                printf("Digite o id do Produto: ");
                scanf("%d\n", &id);

                printf("Digite o numero de unidades: ");
                scanf("%d\n", &qtd);

                loja = aumentaEstoqueLoja(loja, id, qtd);
                break;
            }

            case OPERACAO_VENDER: {
                int id, qtd;

                printf("Digite o id do Produto: ");
                scanf("%d\n", &id);

                printf("Digite o numero de unidades: ");
                scanf("%d\n", &qtd);

                loja = vendeProdutoLoja(loja, id, qtd);
                break;
            }

            case OPERACAO_DESCONTO: {
                int id;
                float desconto;

                printf("Digite o id do Produto: ");
                scanf("%d\n", &id);

                printf("Digite o novo desconto: ");
                scanf("%f\n", &desconto);

                loja = atualizaDescontoLoja(loja, id, desconto);
                break;
            }

            case OPERACAO_INVENTARIO: {
                imprimeProdutosLoja(loja);
                break;
            }

            case OPERACAO_RELATORIO: {
                imprimeRelatorio(loja);
                break;
            }

            default: {
                break;
            }
        }

        putchar('\n');
        imprimeMenu();
    }

    return EXIT_SUCCESS;
}

static void imprimeMenu(void) {
    printf("Menu:\n");
    printf(" C - Cadastrar Produto\n");
    printf(" E - Estocar Produto\n");
    printf(" V - Vender Produto\n");
    printf(" D - Atualizar desconto de Produto\n");
    printf(" I - Imprimir Produtos\n");
    printf(" R - Imprimir Relatorio de Vendas\n");
    printf(" F - Finalizar Programa\n");
}
