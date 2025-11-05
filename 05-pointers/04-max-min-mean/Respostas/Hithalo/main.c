#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define MAX_SIZE_ARRAY 1024

int main(void) {
    int tamanho;
    scanf("%d", &tamanho);

    int numeros[MAX_SIZE_ARRAY];
    LeNumeros(numeros, tamanho);

    int maior, menor;
    float media;
    EncontraMaiorMenorMedia(numeros, tamanho, &maior, &menor, &media);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Media dos elementos: %.2f\n", media);

    return EXIT_SUCCESS;
}
