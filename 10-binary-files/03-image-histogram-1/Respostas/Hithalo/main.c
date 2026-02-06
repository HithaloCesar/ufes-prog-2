#include <stdio.h>
#include <stdlib.h>

#include "imagem.h"

int main(void) {
    char *caminho;
    scanf(" %m[^\n]", &caminho);

    Imagem *imagem = LerImagem(caminho);

    int numElem = ObterNumeroBytesLidos(imagem);
    // Os outputs na verdade querem o número de elementos lidos...
    printf("Numero de bytes lidos: %d\n", numElem);
    ImprimirImagem(imagem);

    DestruirImagem(imagem);
    free(caminho);

    return EXIT_SUCCESS;
}
