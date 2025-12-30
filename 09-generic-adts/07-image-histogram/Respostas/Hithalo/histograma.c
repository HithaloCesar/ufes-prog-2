#include "histograma.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PIXEL_POSSIVEIS_VALORES 256
#define PIXEL_VALOR_MAXIMO 255

struct tHistograma {
    int *buckets;
    int nIntervalos;
    int tamIntervalo;
};

Histograma *CalcularHistograma(Imagem *img, int nIntervalos) {
    Histograma *h = calloc(1, sizeof(*h));
    h->buckets = calloc(nIntervalos, sizeof(*h->buckets));
    h->nIntervalos = nIntervalos;
    h->tamIntervalo = ceil(PIXEL_POSSIVEIS_VALORES / (float)nIntervalos);

    int altura = ObterAltura(img);
    int largura = ObterLargura(img);
    Tipo tipo = ObterTipoImagem(img);
    void *dados = ObterDadosImagem(img);

    int qtdDados = altura * largura;
    for (int i = 0; i < qtdDados; i++) {
        void *dado;
        switch (tipo) {
            case INT: {
                dado = dados + i * sizeof(int);
                int *d = (int *)dado;
                int bucket_idx = *d / h->tamIntervalo;
                h->buckets[bucket_idx]++;
                break;
            }
            case FLOAT: {
                dado = dados + i * sizeof(float);
                float *d = (float *)dado;
                int bucket_idx = *d * PIXEL_VALOR_MAXIMO / h->tamIntervalo;
                h->buckets[bucket_idx]++;
                break;
            }
        }
    }

    return h;
}

void MostrarHistograma(Histograma *h) {
    int inicio = 0;
    int fim = h->tamIntervalo;
    for (int i = 0; i < h->nIntervalos; i++) {
        printf("[%d, %d): %d\n", inicio, fim, h->buckets[i]);
        inicio = fim;
        fim += h->tamIntervalo;
    }
}

void DestruirHistograma(Histograma *h) {
    free(h->buckets);
    free(h);
}
