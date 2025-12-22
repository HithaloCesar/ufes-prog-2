#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "locadora.h"

#define TAM_MAX_STRING 32

int main(void) {
    tLocadora *locadora = CriarLocadora();

    bool continuarExecucao = true;
    bool primeiraOperacao = true;
    while (continuarExecucao) {
        char operacao[TAM_MAX_STRING];
        if (scanf(" %[^\n]", operacao) != 1) {
            continuarExecucao = false;
            continue;
        }
        getchar();

        if (primeiraOperacao) {
            primeiraOperacao = false;
        } else {
            putchar('\n');
        }

        if (!strcmp(operacao, "Cadastrar")) {
            LerCadastroLocadora(locadora);
        } else if (!strcmp(operacao, "Estoque")) {
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
            scanf(" #");
            getchar();
        } else if (!strcmp(operacao, "Alugar")) {
            LerAluguelLocadora(locadora);
        } else if (!strcmp(operacao, "Devolver")) {
            LerDevolucaoLocadora(locadora);
        }
    }

    ConsultarLucroLocadora(locadora);

    DestruirLocadora(locadora);

    return EXIT_SUCCESS;
}
