#include "missil.h"
#include <stdlib.h>
#include <stdio.h>

struct missil {
    char nome[MAX_TAM + 1];
    float x, y;
    float poder;
};

tMissil LeMissil(void) {
    tMissil missil = calloc(1, sizeof(*missil));

    scanf(
        " %s %f %f %f",
        missil->nome,
        &missil->x,
        &missil->y,
        &missil->poder
    );
    getchar();

    return missil;
}

void ImprimeMissil(tMissil missil) {
    printf("M-%s: %.2f\n", missil->nome, missil->poder);
}

void LiberaMissil(tMissil missil) {
    free(missil);
}

float GetMissilY(tMissil missil) {
    return missil->y;
}

float GetMissilX(tMissil missil) {
    return missil->x;
}

float GetMissilPoder(tMissil missil) {
    return missil->poder;
}

void ReduzPoder(tMissil missil, float valor) {
    missil->poder -= valor;

    if (missil->poder < 0) {
        missil->poder = 0;
    }
}
