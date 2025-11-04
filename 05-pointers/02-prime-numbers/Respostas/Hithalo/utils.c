#include "utils.h"
#include <stdio.h>

void LeIntervalo(int *m, int *n) {
    scanf("%d %d", m, n);
}

int EhPrimo(int n) {
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

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior) {
    *menor = -1;
    *maior = -1;

    for (int i = m; i <= n; i++) {
        if (EhPrimo(i)) {
            *menor = i;
            break;
        }
    }

    if (*menor == -1) {
        return;
    }

    for (int i = n; i >= m; i--) {
        if (EhPrimo(i)) {
            *maior = i;
            break;
        }
    }
}
