#include "computador.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct JogoEstatisticas {
    int qtdVitorias;
    int qtdDerrotas;
} tJogoEstatisticas;

struct Computador {
    tJogo *jogo;
    tJogoEstatisticas *jogoStats;
};

static void LeN(int *n);
static void LeIntervalo(int *min, int *max);
static void LeOpcao(char *ch);

tComputador *CriaComputador(void) {
    tComputador *c = calloc(1, sizeof(*c));

    return c;
}

void DestroiComputador(tComputador *c) {
    DestroiJogo(c->jogo);
    free(c->jogoStats);
    free(c);
}

void GerenciaJogo(tComputador *c) {
    c->jogoStats = calloc(1, sizeof(*c->jogoStats));
    c->jogo = CriaJogo();

    printf("Jogo de adivinhação\n");

    bool continuarJogando = true;
    while (continuarJogando) {
        int n;
        LeN(&n);

        int min, max;
        LeIntervalo(&min, &max);

        DefineMinimo(c->jogo, min);
        DefineMaximo(c->jogo, max);

        CalculaValorASerAdivinhado(c->jogo, n);
        CalculaNumeroTentativas(c->jogo);

        int vitoria = ProcessaTentativas(c->jogo);
        vitoria ? c->jogoStats->qtdVitorias++ : c->jogoStats->qtdDerrotas++;

        putchar('\n');
        char ch;
        LeOpcao(&ch);
        if (ch == 'n') {
            continuarJogando = false;
        }
    }

    DestroiJogo(c->jogo);
    c->jogo = NULL;
}

void ImprimeRelatorio(tComputador *c) {
    int totalJogos = c->jogoStats->qtdVitorias + c->jogoStats->qtdDerrotas;

    printf(
        "Obrigado por jogar comigo. Desta vez, voce jogou %d jogo(s), "
        "ganhou %d jogo(s) e perdeu %d jogo(s). Ate a proxima!\n",
        c->jogoStats->qtdVitorias + c->jogoStats->qtdDerrotas,
        c->jogoStats->qtdVitorias,
        c->jogoStats->qtdDerrotas
    );
}

static void LeN(int *n) {
    bool leituraOk = false;
    while (!leituraOk) {
        printf("Forneca um numero no intervalo entre 1 e 10000:\n");
        scanf("%d", n);
        getchar();

        if (*n < 1 || *n > 10000) {
            continue;
        }

        leituraOk = true;
    }
}

static void LeIntervalo(int *min, int *max) {
    bool leituraOk = false;
    while (!leituraOk) {
        printf("Forneca um intervalo de numeros naturais:\n");
        scanf("%d %d", min, max);
        getchar();

        if (*min > *max) {
            printf("O primeiro numero do intervalo deve ser inferior ao segundo\n");
            continue;
        }

        if (*min < 0) {
            printf("O intervalo deve ser composto de numeros naturais!\n");
            continue;
        }

        if (*max >= 1000000000) {
            printf(
                "O segundo numero do intervalo deve ser menor que "
                "1.000.000.000\n"
            );
            continue;
        }

        leituraOk = true;
    }
}

static void LeOpcao(char *ch) {
    bool leituraOk = false;
    while (!leituraOk) {
        printf("Deseja continuar a jogar (s/n):\n");
        scanf(" %c", ch);
        if (*ch != 's' && *ch != 'n') {
            printf("Voce deve digitar s ou n!\n");
            continue;
        }
        leituraOk = true;
    }
}
