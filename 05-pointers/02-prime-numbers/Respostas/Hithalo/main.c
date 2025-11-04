#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(void) {
    int nIntervalos;
    scanf("%d", &nIntervalos);

    for (int i = 0; i < nIntervalos; i++) {
        int m, n;
        LeIntervalo(&m, &n);

        int menor, maior;
        ObtemMaiorEMenorPrimo(m, n, &menor, &maior);

        printf("%d %d\n", menor, maior);
    }

    return EXIT_SUCCESS;
}
