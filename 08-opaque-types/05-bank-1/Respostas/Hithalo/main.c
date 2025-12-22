#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "banco.h"

typedef enum {
    OPERACAO_ABRIR_CONTA = 'A',
    OPERACAO_DEPOSITAR = 'D',
    OPERACAO_SACAR = 'S',
    OPERACAO_TRANSFERIR = 'T',
    OPERACAO_RELATORIO = 'R',
    OPERACAO_FINALIZAR = 'F'
} tOperacao;

int main(void) {
    tBanco *banco = CriaBanco();

    bool continuarExecucao = true;
    while (continuarExecucao) {
        char operacao;
        scanf(" %c", &operacao);
        getchar();

        switch (operacao) {
            case OPERACAO_ABRIR_CONTA: {
                AbreContaBanco(banco);
                break;
            }
            case OPERACAO_DEPOSITAR: {
                DepositoContaBanco(banco);
                break;
            }
            case OPERACAO_SACAR: {
                SaqueContaBanco(banco);
                break;
            }
            case OPERACAO_TRANSFERIR: {
                TransferenciaContaBanco(banco);
                break;
            }
            case OPERACAO_RELATORIO: {
                ImprimeRelatorioBanco(banco);
                break;
            }
            case OPERACAO_FINALIZAR: {
                continuarExecucao = false;
                break;
            }
            default: {
                printf("Opcao invalida\n");
                break;
            }
        }
    }

    DestroiBanco(banco);

    return EXIT_SUCCESS;
}
