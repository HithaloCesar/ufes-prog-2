#include "defesa.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct defesa {
    char nome[MAX_TAM + 1];
    float x, y;
    char tipo;
    float tamanho;
    float poder;
    int quantidade;
};

tDefesa LeDefesa(void) {
    tDefesa defesa = calloc(1, sizeof(*defesa));

    scanf(
        " %s %f %f %c %f %f %d",
        defesa->nome,
        &defesa->x,
        &defesa->y,
        &defesa->tipo,
        &defesa->tamanho,
        &defesa->poder,
        &defesa->quantidade
    );
    getchar();

    return defesa;
}

void ImprimeDefesa(tDefesa defesa) {
    printf("D-%s: %d\n", defesa->nome, defesa->quantidade);
}

void LiberaDefesa(tDefesa defesa) {
    free(defesa);
}

static float DistanciaEuclidiana(float x1, float y1, float x2, float y2) {
    float xDiffAoQuadrado = (x2 - x1) * (x2 - x1);
    float yDiffAoQuadrado = (y2 - y1) * (y2 - y1);
    float distancia = sqrt(xDiffAoQuadrado + yDiffAoQuadrado);

    return distancia;
}

int VerificaSeDentroArea(tDefesa defesa, float x, float y) {
    int dentroDaArea = 0;

    switch (defesa->tipo) {
        case CIRCULO: {
            float raio = defesa->tamanho;
            float distancia = DistanciaEuclidiana(defesa->x, defesa->y, x, y);
            dentroDaArea = distancia <= raio;
            break;
        }
        case QUADRADO: {
            float metadeDiagonal = defesa->tamanho;
            float lado = 2 * metadeDiagonal / sqrt(2);
            float menorX = defesa->x - lado / 2;
            float maiorX = defesa->x + lado / 2;
            float menorY = defesa->y - lado / 2;
            float maiorY = defesa->y + lado / 2;
            if (x >= menorX && x <= maiorX && y >= menorY && y <= maiorY) {
                dentroDaArea = 1;
            }
            break;
        }
        default: {
            break;
        }
    }

    return dentroDaArea;
}

void UsaDefesa(tDefesa defesa) {
    if (defesa->quantidade <= 0) {
        return;
    }

    defesa->quantidade--;
}

float GetDefesaPoder(tDefesa defesa) {
    return defesa->poder;
}

int PodeDefender(tDefesa defesa) {
    return defesa->quantidade > 0;
}
