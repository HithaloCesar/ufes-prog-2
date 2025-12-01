#include "utils_char2.h"
#include <stdlib.h>
#include <stdio.h>

char *CriaVetorTamPadrao() {
    char *vetor = malloc((TAM_PADRAO + 1) * sizeof(*vetor));

    if (vetor == NULL) {
        return NULL;
    }

    for (int i = 0; i < TAM_PADRAO; i++) {
        vetor[i] = '_';
    }
    vetor[TAM_PADRAO] = '\0';

    return vetor;
}

char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo) {
    int tamanho = tamanhoantigo + TAM_PADRAO;
    char *novovetor = realloc(vetor, (tamanho + 1) * sizeof(*vetor));

    if (novovetor == NULL) {
        return NULL;
    }

    for (int i = tamanhoantigo; i < tamanho; i++) {
        novovetor[i] = '_';
    }

    novovetor[tamanho] = '\0';

    return novovetor;
}

char *LeVetor(char *vetor, int *tamanho) {
    char c;
    for (int i = 0; (c = getchar()) != '\n'; i++) {
        if (i == *tamanho) {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            if (vetor == NULL) {
                return NULL;
            }
            *tamanho += TAM_PADRAO;
        }

        vetor[i] = c;
    }

    return vetor;
}

void ImprimeString(char *vetor) {
    printf("%s", vetor);
}

void LiberaVetor(char *vetor) {
    free(vetor);
}
