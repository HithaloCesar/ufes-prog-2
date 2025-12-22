#include "jogada.h"
#include <stdlib.h>
#include <stdio.h>

tJogada *CriaJogada(void) {
    tJogada *jogada = calloc(1, sizeof((*jogada)));

    jogada->sucesso = 0;

    return jogada;
}

void DestroiJogada(tJogada *jogada) {
    free(jogada);
}

void LeJogada(tJogada *jogada) {
    printf("Digite uma posicao (x e y):\n");
    if (scanf("%d %d", &jogada->x, &jogada->y) == 2) {
        getchar();
        jogada->sucesso = 1;
    }
}

int ObtemJogadaX(tJogada *jogada) {
    return jogada->x;
}

int ObtemJogadaY(tJogada *jogada) {
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada *jogada) {
    return jogada->sucesso;
}
