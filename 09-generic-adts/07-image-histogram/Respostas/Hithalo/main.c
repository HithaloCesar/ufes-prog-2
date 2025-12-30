#include <stdlib.h>
#include <stdio.h>
#include "imagem.h"
#include "histograma.h"

int main(void) {
    int nIntervalos;
    scanf("%d", &nIntervalos);

    Imagem *img = LerImagem();

    Histograma *histograma = CalcularHistograma(img, nIntervalos);

    MostrarHistograma(histograma);

    DestruirHistograma(histograma);
    DestruirImagem(img);

    return EXIT_SUCCESS;
}
