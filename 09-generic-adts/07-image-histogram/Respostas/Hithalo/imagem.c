#include "imagem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tImagem {
    void *dados;
    int altura;
    int largura;
    Tipo tipo;
};

int ObterAltura(Imagem *img) {
    return img->altura;
}

int ObterLargura(Imagem *img) {
    return img->largura;
}

Tipo ObterTipoImagem(Imagem *img) {
    return img->tipo;
}

void *ObterDadosImagem(Imagem *img) {
    return img->dados;
}

Imagem *CriarImagem(int altura, int largura, Tipo tipo) {
    Imagem *img = calloc(1, sizeof(*img));

    img->altura = altura;
    img->largura = largura;
    img->tipo = tipo;

    int sizeDado;
    switch (tipo) {
        case INT: {
            sizeDado = sizeof(int);
            break;
        }
        case FLOAT: {
            sizeDado = sizeof(float);
            break;
        }
    }

    int qtdDados = altura * largura;
    img->dados = calloc(qtdDados, sizeDado);

    return img;
}

static void LerImagemCallBack(
    Imagem *img,
    void (*LeDado)(void *),
    void (*DestroiDado)(void *),
    int sizeDado
) {
    int qtdDados = img->altura * img->largura;
    void *dados = calloc(qtdDados, sizeDado);

    for (int i = 0; i < qtdDados; i++) {
        int offset = i * sizeDado;

        void *dado = dados + offset;
        void *p = img->dados + offset;

        LeDado(dado);
        memcpy(p, dado, sizeDado);
    }

    free(dados);
}

static void LeInt(void *n) {
    scanf("%d", n);
    getchar();
}

static void LeFloat(void *f) {
    scanf("%f", f);
    getchar();
}

static void DestroiSimples(void *n) {
    free(n);
}

Imagem *LerImagem(void) {
    int altura, largura, t;
    scanf("%d %d %d", &altura, &largura, &t);
    getchar();
    Tipo tipo = (Tipo)t;

    Imagem *img = CriarImagem(altura, largura, tipo);

    switch (tipo) {
        case INT: {
            LerImagemCallBack(img, LeInt, DestroiSimples, sizeof(int));
            break;
        }
        case FLOAT: {
            LerImagemCallBack(img, LeFloat, DestroiSimples, sizeof(float));
            break;
        }
    }

    return img;
}

void ImprimirImagemCallback(
    Imagem *img,
    void (*ImprimeDado)(void *),
    int sizeDado
) {
    for (int i = 0; i < img->altura; i++) {
        int sizeAcumulado = i * img->largura * sizeDado;
        char *sep = "";
        for (int j = 0; j < img->largura; j++) {
            void *dado = img->dados + sizeAcumulado + j * sizeDado;
            printf("%s", sep);
            ImprimeDado(dado);
            sep = " ";
        }
        putchar('\n');
    }
}

static void ImprimeInt(void *n) {
    int i = *((int *)n);
    printf("%d", i);
}

static void ImprimeFloat(void *n) {
    float f = *((float *)n);
    printf("%.2f", f);
}

void ImprimirImagem(Imagem *img) {
    switch (img->tipo) {
        case INT: {
            ImprimirImagemCallback(img, ImprimeInt, sizeof(int));
            break;
        }
        case FLOAT: {
            ImprimirImagemCallback(img, ImprimeFloat, sizeof(float));
            break;
        }
    }
}

void DestruirImagem(Imagem *img) {
    free(img->dados);
    free(img);
}
