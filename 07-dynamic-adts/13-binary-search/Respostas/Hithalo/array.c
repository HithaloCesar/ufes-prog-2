#include "array.h"
#include <stdlib.h>
#include <stdio.h>

#define TAM_INICIAL_ARRAY 4

Array *CriarArray(void) {
    Array *array = calloc(1, sizeof(*array));

    return array;
}

void DestruirArray(Array *array) {
    free(array->data);
    free(array);
}

void LerArray(Array *array) {
    int num;
    int qtdNum = 0;
    while (scanf("%d", &num) == 1) {
        if (qtdNum == array->tamanho) {
            if (array->tamanho == 0) {
                array->tamanho = TAM_INICIAL_ARRAY;
            } else {
                array->tamanho *= 2;
            }
            array->data = realloc(
                array->data, array->tamanho * sizeof(*array->data)
            );
        }
        array->data[qtdNum++] = num;
    }
    scanf(".");
    getchar();

    array->tamanho = qtdNum;
    array->data = realloc(array->data, array->tamanho * sizeof(*array->data));
}

static int ComparaArrayInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void OrdenarArray(Array *array) {
    qsort(array->data, array->tamanho, sizeof(*array->data), ComparaArrayInt);
}

int BuscaBinariaArray(Array *array, int elementoBuscado) {
    int limiteInferior = 0;
    int limiteSuperior = array->tamanho - 1;

    while (limiteInferior <= limiteSuperior) {
        int meio = (limiteSuperior + limiteInferior) / 2;

        if (elementoBuscado > array->data[meio]) {
            limiteInferior = meio + 1;
        } else if (elementoBuscado < array->data[meio]) {
            limiteSuperior = meio - 1;
        } else {
            return meio;
        }
    }

    return -1;
}
