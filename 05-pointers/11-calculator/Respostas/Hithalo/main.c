#include <stdlib.h>
#include <stdio.h>
#include "calculadora.h"

typedef enum {
    OPERACAO_ADICAO = 'a',
    OPERACAO_SUBTRACAO = 's',
    OPERACAO_MULTIPLICACAO = 'm',
    OPERACAO_DIVISAO = 'd',
    OPERACAO_FINALIZAR = 'f'
} Operacao;

static float adicao(float n1, float n2);

static float subtracao(float n1, float n2);

static float multiplicacao(float n1, float n2);

static float divisao(float n1, float n2);

int main(void) {
    char operacao;
    while (scanf(" %c", &operacao) == 1 && operacao != OPERACAO_FINALIZAR) {
        float n1, n2;
        scanf("%f %f", &n1, &n2);

        float result;
        char operacaoSinal;
        switch (operacao) {
            case OPERACAO_ADICAO: {
                result = Calcular(n1, n2, adicao);
                operacaoSinal = '+';
                break;
            }
            case OPERACAO_SUBTRACAO: {
                result = Calcular(n1, n2, subtracao);
                operacaoSinal = '-';
                break;
            }
            case OPERACAO_MULTIPLICACAO: {
                result = Calcular(n1, n2, multiplicacao);
                operacaoSinal = 'x';
                break;
            }
            case OPERACAO_DIVISAO: {
                result = Calcular(n1, n2, divisao);
                operacaoSinal = '/';
                break;
            }
            default: {
                break;
            }
        }

        printf("%.2f %c %.2f = %.2f\n", n1, operacaoSinal, n2, result);
    }

    return EXIT_SUCCESS;
}

static float adicao(float n1, float n2) {
    return n1 + n2;
}

static float subtracao(float n1, float n2) {
    return n1 - n2;
}

static float multiplicacao(float n1, float n2) {
    return n1 * n2;
}

static float divisao(float n1, float n2) {
    return n1 / n2;
}
