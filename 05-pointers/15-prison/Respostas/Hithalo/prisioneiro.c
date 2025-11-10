#include "prisioneiro.h"
#include <stdio.h>
#include <string.h>

tPrisioneiro criaPrisioneiro(char *nome, int pena) {
    tPrisioneiro p;

    strcpy(p.nome, nome);
    p.pena = pena;
    p.tempoPassado = 0;

    return p;
}

void passaTempoPrisioneiro(tPrisioneiro *prisioneiro) {
    prisioneiro->tempoPassado++;
}

void fogePrisioneiro(tPrisioneiro *prisioneiro) {
    printf("Detento %s fugiu!\n", prisioneiro->nome);
}

int acabouPenaPrisioneiro(tPrisioneiro *prisioneiro) {
    return prisioneiro->tempoPassado >= prisioneiro->pena;
}

void liberaPrisioneiroCumpriuPena(tPrisioneiro *prisioneiro) {
    printf("Detento %s cumpriu sua pena e foi liberado\n", prisioneiro->nome);
}

void liberaPrisioneiroFimPrograma(tPrisioneiro *prisioneiro) {
    // Why a parameter here?...
    printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
}
