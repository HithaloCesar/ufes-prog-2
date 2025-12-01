#include <stdlib.h>
#include <stdio.h>
#include "utils_char2.h"

int main(void) {
    char *vetor = CriaVetorTamPadrao();
    if (vetor == NULL) {
        fprintf(stderr, "ERROR: The memory could not be written.\n");
        return EXIT_FAILURE;
    }

    int tamanho = TAM_PADRAO;

    char *vetorlido = LeVetor(vetor, &tamanho);

    if (vetorlido == NULL) {
        fprintf(stderr, "ERROR: The memory could not be written.\n");
        LiberaVetor(vetor);
        return EXIT_FAILURE;
    }

    ImprimeString(vetorlido);

    LiberaVetor(vetorlido);

    return EXIT_SUCCESS;
}
