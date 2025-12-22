#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "eletronica.h"

#define MAX_TAM_OPERACAO 32

int main(void) {
    char nomeEletronica[QTDMAXNOMEELETRONICA];
    scanf(" %[^\n]", nomeEletronica);
    getchar();
    tEletronica *eletronica = criaEletronica(nomeEletronica);

    bool continuarExecucao = true;
    while (continuarExecucao) {
        char operacao[MAX_TAM_OPERACAO];
        scanf(" %[^\n]", operacao);
        getchar();

        if (!strcmp(operacao, "CADASTRA")) {
            tTecnico *tecnico = leTecnico();
            cadastraTecnico(eletronica, tecnico);
        } else if (!strcmp(operacao, "TICKET")) {
            tTicket *ticket = leTicket();
            char idTecnico[MAXIDTECNICO];
            scanf(" %[^\n]", idTecnico);
            getchar();
            atribuiTicketEletronica(eletronica, idTecnico, ticket);
        } else if (!strcmp(operacao, "CONCLUI")) {
            int codigoTicket;
            scanf("%d", &codigoTicket);
            getchar();
            alteraSituacaoTicketEletronica(eletronica, codigoTicket);
        } else if (!strcmp(operacao, "IMPRIME")) {
            imprimeEletronica(eletronica);
        } else if (!strcmp(operacao, "AUMENTA")) {
            char idTecnico[MAXIDTECNICO];
            scanf(" %[^\n]", idTecnico);
            getchar();
            aumentaCargaTecnicoEletronica(eletronica, idTecnico);
        } else if (!strcmp(operacao, "FIM")) {
            continuarExecucao = false;
        }
    }

    destroiEletronica(eletronica);

    return EXIT_SUCCESS;
}
