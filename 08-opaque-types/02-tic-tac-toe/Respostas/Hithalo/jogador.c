#include "jogador.h"
#include "jogada.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Jogador {
    int id;
};

tJogador *CriaJogador(int idJogador) {
    tJogador *jogador = malloc(sizeof(*jogador));

    jogador->id = idJogador;

    return jogador;
}

void DestroiJogador(tJogador *jogador) {
    free(jogador);
}

void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    tJogada *jogada = CriaJogada();

    bool sucesso = false;
    while (!sucesso) {
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);
        if (!FoiJogadaBemSucedida(jogada)) {
            printf("Formato invalido!\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        int x = ObtemJogadaX(jogada);
        int y = ObtemJogadaY(jogada);
        if (!EhPosicaoValidaTabuleiro(x, y)) {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        } else if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)) {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        } else {
            printf("Jogada [%d,%d]!\n", x, y);
            MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
            sucesso = true;
        }
    }

    free(jogada);
}

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro) {
    // Verificação das horizontais
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        bool vitoria = true;
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            int posicaoMarcada = EstaMarcadaPosicaoPecaTabuleiro(
                tabuleiro, j, i, jogador->id
            );
            if (!posicaoMarcada) {
                vitoria = false;
                break;
            }
        }
        if (vitoria) {
            return 1;
        }
    }

    // Verificação das verticais
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        bool vitoria = true;
        for (int i = 0; i < TAM_TABULEIRO; i++) {
            int posicaoMarcada = EstaMarcadaPosicaoPecaTabuleiro(
                tabuleiro, j, i, jogador->id
            );
            if (!posicaoMarcada) {
                vitoria = false;
                break;
            }
        }
        if (vitoria) {
            return 1;
        }
    }

    // Verificação da diagonal primária
    bool vitoria = true;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        int posicaoMarcada = EstaMarcadaPosicaoPecaTabuleiro(
            tabuleiro, i, i, jogador->id
        );
        if (!posicaoMarcada) {
            vitoria = false;
            break;
        }
    }
    if (vitoria) {
        return 1;
    }

    // Verificação da diagonal secundária
    vitoria = true;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        int posicaoMarcada = EstaMarcadaPosicaoPecaTabuleiro(
            tabuleiro, TAM_TABULEIRO - 1 - i, i, jogador->id
        );
        if (!posicaoMarcada) {
            vitoria = false;
            break;
        }
    }
    if (vitoria) {
        return 1;
    }

    return 0;
}
