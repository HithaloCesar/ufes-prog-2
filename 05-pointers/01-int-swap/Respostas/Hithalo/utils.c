#include "utils.h"
#include <stdio.h>

int TrocaInterios(int *n1, int *n2) {
    if (n1 == NULL || n2 == NULL) {
        return 0;
    }

    if (*n1 <= *n2) {
        return 0;
    }

    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;

    return 1;
}
