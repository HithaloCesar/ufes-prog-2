#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Jogo {
    int min, max;
    int x;
    int maxTentativas;
};

tJogo *CriaJogo(void) {
    tJogo *j = calloc(1, sizeof(*j));

    return j;
}

void DestroiJogo(tJogo *jogo) {
    free(jogo);
}

void DefineMaximo(tJogo *jogo, int max) {
    jogo->max = max;
}

void DefineMinimo(tJogo *jogo, int min) {
    jogo->min = min;
}

static int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    if (n % 2 == 0) {
        return 0;
    }

    for (int den = 3; den * den <= n; den += 2) {
        if (n % den == 0) {
            return 0;
        }
    }

    return 1;
}

static int fibonacci_prime(int n) {
    if (n <= 0) {
        return -1;
    }

    int numPrimos = 0;

    int n0 = 1;
    int n1 = 1;

    while (numPrimos != n) {
        int old_n1 = n1;
        n1 = n0;
        n0 += old_n1;

        if (is_prime(n0)) {
            numPrimos++;
        }
    }

    return n0;
}

void CalculaValorASerAdivinhado(tJogo *jogo, int n) {
    int f = fibonacci_prime(n);
    int r = f % 101;

    jogo->x = round((r / 100.0) * (jogo->max - jogo->min) + jogo->min);
}

void CalculaNumeroTentativas(tJogo *jogo) {
    jogo->maxTentativas = (int)log2(jogo->max - jogo->min + 1) + 1;
}

int ProcessaTentativas(tJogo *jogo) {
    putchar('\n');
    printf("Voce tem direito a %d tentativas\n", jogo->maxTentativas);

    for (int i = 0; i < jogo->maxTentativas; i++) {
        printf("Tentativa %d:\n", i + 1);

        int tentativa;
        scanf("%d", &tentativa);
        getchar();

        if (tentativa > jogo->x) {
            printf("Alta\n");
        } else if (tentativa < jogo->x) {
            printf("Baixa\n");
        } else {
            printf("Parabens, voce ganhou!\n");
            return 1;
        }
    }

    printf("Voce perdeu! O numero escolhido foi %d\n", jogo->x);
    return 0;
}
