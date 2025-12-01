#include <stdlib.h>
#include <stdio.h>
#include "utils_char.h"

int main(void) {
    int tamanho;
    scanf("%d\n", &tamanho);

    char *vetor = CriaVetor(tamanho);
    if (vetor == NULL) {
        fprintf(stderr, "ERROR: The memory could not be written.\n");
        return EXIT_FAILURE;
    }

    ImprimeString(vetor, tamanho);

    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);

    LiberaVetor(vetor);

    return EXIT_SUCCESS;
}
