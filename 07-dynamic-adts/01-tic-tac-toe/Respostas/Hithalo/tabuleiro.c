#include "tabuleiro.h"
#include <stdlib.h>
#include <stdio.h>

#define PECA_1_CHAR 'X'
#define PECA_2_CHAR '0'
#define PECA_VAZIO_CHAR '-'

tTabuleiro *CriaTabuleiro(void) {
    tTabuleiro *tabuleiro = malloc(sizeof(*tabuleiro));

    tabuleiro->posicoes = malloc(TAM_TABULEIRO * sizeof(*tabuleiro->posicoes));

    for (size_t i = 0; i < TAM_TABULEIRO; i++) {
        tabuleiro->posicoes[i] = malloc(
            TAM_TABULEIRO * sizeof(*tabuleiro->posicoes[i])
        );
    }

    tabuleiro->peca1 = PECA_1_CHAR;
    tabuleiro->peca2 = PECA_2_CHAR;
    tabuleiro->pecaVazio = PECA_VAZIO_CHAR;

    for (size_t i = 0; i < TAM_TABULEIRO; i++) {
        for (size_t j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro->posicoes[i][j] = PECA_VAZIO_CHAR;
        }
    }

    return tabuleiro;
}

void DestroiTabuleiro(tTabuleiro *tabuleiro) {
    for (size_t i = 0; i < TAM_TABULEIRO; i++) {
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y) {
    if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
        return;
    }

    tabuleiro->posicoes[y][x] = (peca == PECA_1) ? PECA_1_CHAR : PECA_2_CHAR;
}

int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro) {
    for (size_t i = 0; i < TAM_TABULEIRO; i++) {
        for (size_t j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro->posicoes[i][j] == PECA_VAZIO_CHAR) {
                return 1;
            }
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(
    tTabuleiro *tabuleiro,
    int x,
    int y,
    int peca
) {
    if (!EhPosicaoValidaTabuleiro(x, y)) {
        return 0;
    }

    char pecaChar = (peca == PECA_1) ? PECA_1_CHAR : PECA_2_CHAR;

    return tabuleiro->posicoes[y][x] == pecaChar;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y) {
    if (!EhPosicaoValidaTabuleiro(x, y)) {
        return 0;
    }

    return tabuleiro->posicoes[y][x] == PECA_VAZIO_CHAR;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO;
}

void ImprimeTabuleiro(tTabuleiro *tabuleiro) {
    for (size_t i = 0; i < TAM_TABULEIRO; i++) {
        putchar('\t');
        for (size_t j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        putchar('\n');
    }
}
