#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int main(void) {
    Array *array = CriarArray();
    LerArray(array);

    int elementoBuscado;
    scanf("%d", &elementoBuscado);
    getchar();

    OrdenarArray(array);
    int i = BuscaBinariaArray(array, elementoBuscado);

    if (i < 0) {
        printf("Elemento %d não encontrado no array (-1).\n", elementoBuscado);
    } else {
        printf("Elemento %d encontrado no índice %d.\n", elementoBuscado, i);
    }

    DestruirArray(array);

    return EXIT_SUCCESS;
}
