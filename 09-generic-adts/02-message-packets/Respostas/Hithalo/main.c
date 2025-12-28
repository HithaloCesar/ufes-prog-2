#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "gerenciadorpacotes.h"

enum operacao {
    OPERACAO_NOVO_PACOTE = 1,
    OPERACAO_IMPRIMIR_PACOTE_NO_INDICE,
    OPERACAO_IMPRIMIR_TODOS_PACOTES_E_SAIR
};

static void ImprimeMenu(void);

int main(void) {
    tGerenciador *geren = CriaGerenciador();

    bool continuarExecucao = true;
    while (continuarExecucao) {
        ImprimeMenu();

        int operacao;
        scanf("%d", &operacao);
        getchar();

        switch (operacao) {
            case OPERACAO_NOVO_PACOTE: {
                puts("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");

                int tipo, numElem;
                scanf("%d %d", &tipo, &numElem);

                if (tipo != CHAR && tipo != INT) {
                    puts("Digite um tipo valido!");
                    break;
                }

                tPacote *pac = CriaPacote(tipo, numElem);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(geren, pac);
                break;
            }
            case OPERACAO_IMPRIMIR_PACOTE_NO_INDICE: {
                int idx;
                scanf("%d", &idx);
                getchar();

                ImprimirPacoteNoIndice(geren, idx);

                break;
            }
            case OPERACAO_IMPRIMIR_TODOS_PACOTES_E_SAIR: {
                ImprimirTodosPacotes(geren);
                continuarExecucao = false;
                break;
            }
            default: {
                puts("Escolha uma opcao valida para o menu!");
                break;
            }
        }
    }

    DestroiGerenciador(geren);

    return EXIT_SUCCESS;
}

static void ImprimeMenu(void) {
    puts("Escolha uma opcao:");
    puts("\t(1) Cadastrar um novo pacote");
    puts("\t(2) Imprimir um pacote especifico");
    puts("\t(3) Imprimir todos os pacotes e sair");
}
