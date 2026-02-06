#include "imagem.h"

#include <stdio.h>
#include <stdlib.h>

typedef void (*ImprimePixel)(void *);

struct tImagem {
    void *pixels;
    int numBytesPixel;
    int numLinhas;
    int numColunas;
    int numElem;
    Tipo tipo;
    ImprimePixel imprimePixel;
};

static void ImprimeIntGenerico(void *n);
static void ImprimeFloatGenerico(void *n);

Imagem *LerImagem(const char *caminho) {
    FILE *arquivoBinario = fopen(caminho, "rb");

    Imagem *img = calloc(1, sizeof(*img));

    img->numElem += fread(&img->numLinhas, sizeof(img->numLinhas), 1, arquivoBinario);
    img->numElem += fread(&img->numColunas, sizeof(img->numColunas), 1, arquivoBinario);
    img->numElem += fread(&img->tipo, sizeof(img->tipo), 1, arquivoBinario);

    switch (img->tipo) {
        case FLOAT:
            img->numBytesPixel = sizeof(float);
            img->imprimePixel = ImprimeFloatGenerico;
            break;
        case INT:
            img->numBytesPixel = sizeof(int);
            img->imprimePixel = ImprimeIntGenerico;
            break;
    }

    int qtdPixels = img->numLinhas * img->numColunas;
    img->pixels = malloc(qtdPixels * img->numBytesPixel);

    img->numElem += fread(
        img->pixels,
        img->numBytesPixel,
        qtdPixels,
        arquivoBinario
    );

    fclose(arquivoBinario);

    return img;
}

void DestruirImagem(Imagem *img) {
    free(img->pixels);
    free(img);
}

int ObterNumeroBytesLidos(Imagem *img) {
    // Os outputs na verdade querem o número de elementos lidos...
    return img->numElem;
}

void ImprimirImagem(Imagem *img) {
    for (int i = 0; i < img->numLinhas; i++) {
        char *sep = "";
        for (int j = 0; j < img->numColunas; j++) {
            printf("%s", sep);
            sep = " ";
            int elem_offset = i * img->numColunas + j;
            int bytes_offset = img->numBytesPixel * elem_offset;
            img->imprimePixel(img->pixels + bytes_offset);
        }
        putchar('\n');
    }
}

static void ImprimeIntGenerico(void *n) {
    printf("%d", *(int *)n);
}

static void ImprimeFloatGenerico(void *n) {
    printf("%.2f", *(float *)n);
}
