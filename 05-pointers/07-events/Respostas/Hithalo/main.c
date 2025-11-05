#include <stdlib.h>
#include <stdio.h>
#include "evento.h"

typedef enum {
    OPCAO_CADASTRAR = 1,
    OPCAO_EXIBIR,
    OPCAO_TROCAR_DATA,
    OPCAO_TROCAR_INDICES,
    OPCAO_SAIR
} Opcao;

void imprimeMenu(void) {
    putchar('\n');
    printf("===== Menu =====\n");
    printf("1 - Cadastrar um evento\n");
    printf("2 - Exibir todos os eventos\n");
    printf("3 - Trocar data de um evento\n");
    printf("4 - Trocar a posicao entre dois eventos\n");
    printf("5 - Sair\n");
}

int main(void) {
    Evento eventos[MAX_EVENTOS];
    int numEventos = 0;
    int opcao = 0;

    imprimeMenu();

    while (opcao != 5) {
        scanf("%d", &opcao);

        switch (opcao) {
            case OPCAO_CADASTRAR:
                cadastrarEvento(eventos, &numEventos);
                break;

            case OPCAO_EXIBIR:
                exibirEventos(eventos, &numEventos);
                break;

            case OPCAO_TROCAR_DATA:
                trocarDataEvento(eventos, &numEventos);
                break;

            case OPCAO_TROCAR_INDICES:
                int indiceA, indiceB;
                scanf("%d %d", &indiceA, &indiceB);
                trocarIndicesEventos(eventos, &indiceA, &indiceB, &numEventos);
                break;

            case OPCAO_SAIR:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return EXIT_SUCCESS;
}
