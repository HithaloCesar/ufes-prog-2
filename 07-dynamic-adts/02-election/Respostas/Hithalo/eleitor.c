#include "eleitor.h"
#include <stdlib.h>
#include <stdio.h>

tEleitor *CriaEleitor(void) {
    tEleitor *eleitor = calloc(1, sizeof(*eleitor));

    return eleitor;
}

void ApagaEleitor(tEleitor *eleitor) {
    free(eleitor);
}

void LeEleitor(tEleitor *eleitor) {
    scanf("%d %d %d", &eleitor->id, &eleitor->votoP, &eleitor->votoG);
    getchar();
}

int ObtemVotoPresidente(tEleitor *eleitor) {
    return eleitor->votoP;
}

int ObtemVotoGovernador(tEleitor *eleitor) {
    return eleitor->votoG;
}

int EhMesmoEleitor(tEleitor *eleitor1, tEleitor *eleitor2) {
    return eleitor1->id == eleitor2->id;
}
