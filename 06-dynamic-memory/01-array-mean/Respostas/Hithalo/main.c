#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(void) {
    int tamanho;
    scanf("%d", &tamanho);

    int *vetor = CriaVetor(tamanho);
    if (vetor == NULL) {
        fprintf(stderr, "ERROR: The memory could not be written.\n");
        return EXIT_FAILURE;
    }

    LeVetor(vetor, tamanho);

    printf("%.2f\n", CalculaMedia(vetor, tamanho));

    LiberaVetor(vetor);

    return EXIT_SUCCESS;
}
