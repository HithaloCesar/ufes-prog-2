#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "banco.h"

enum operacao {
    OPERACAO_ADICIONAR_AGENCIA = 'A',
    OPERACAO_ADICIONAR_CONTA = 'C',
    OPERACAO_FINALIZAR = 'F'
};

int main(void) {
    tBanco *banco = CriaBanco();
    LeBanco(banco);

    bool continuarExecucao = true;
    while (continuarExecucao) {
        char operacao;
        scanf(" %c", &operacao);

        switch (operacao) {
            case OPERACAO_ADICIONAR_AGENCIA: {
                tAgencia *agencia = CriaAgencia();
                LeAgencia(agencia);
                AdicionaAgencia(banco, agencia);
                break;
            }
            case OPERACAO_ADICIONAR_CONTA: {
                tConta *conta = CriaConta();
                LeConta(conta);

                int numAgencia;
                scanf("%d", &numAgencia);
                getchar();

                InsereContaBanco(banco, numAgencia, conta);
                break;
            }
            case OPERACAO_FINALIZAR: {
                continuarExecucao = false;
                break;
            }
        }
    }

    ImprimeRelatorioBanco(banco);

    DestroiBanco(banco);

    return EXIT_SUCCESS;
}
