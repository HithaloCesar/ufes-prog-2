#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "utils.h"

int main(void) {
    int n1, n2;
    while (scanf("%d %d", &n1, &n2) == 2) {
        int trocou = false;

        if (n2 < n1) {
            trocou = TrocaInterios(&n1, &n2) != 0;
        }

        if (trocou) {
            printf("TROCADO: ");
        } else {
            printf("ORIGINAL: ");
        }

        printf("%d %d\n", n1, n2);
    }

    return EXIT_SUCCESS;
}
