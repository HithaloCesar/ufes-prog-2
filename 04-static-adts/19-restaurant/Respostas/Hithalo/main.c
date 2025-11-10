#include <stdlib.h>
#include <stdio.h>
#include "restaurante.h"

typedef enum {
    OP_REST_ADD_ALIM = 'A',
    OP_REST_USA_ALIM = 'C',
    OP_REST_PRINT = 'I',
    OP_REST_EXIT = 'E'
} op_rest;

int main(void) {
    tRestaurante rest = leRestaurante();

    char operation;
    while (scanf("%c\n", &operation) && operation != OP_REST_EXIT) {
        switch (operation) {
            case OP_REST_ADD_ALIM: {
                tAlimento alimento = leAlimento();
                rest = cadastraAlimento(rest, alimento);
                break;
            }

            case OP_REST_USA_ALIM: {
                char nome[32];
                float qtd;
                scanf(" %[^\n]\n", nome);
                scanf("%f", &qtd);
                rest = consumirAlimentoRestaurante(rest, nome, qtd);
                break;
            }

            case OP_REST_PRINT: {
                imprimeRestaurante(rest);
                break;
            }

            default: {
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
