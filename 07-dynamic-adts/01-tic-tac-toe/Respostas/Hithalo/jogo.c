#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

tJogo *CriaJogo(void) {
    tJogo *jogo = malloc(sizeof(*jogo));

    return jogo;
}

void ComecaJogo(tJogo *jogo) {
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(PECA_1);
    jogo->jogador2 = CriaJogador(PECA_2);

    bool turnoJogador1 = true;
    while (!AcabouJogo(jogo)) {
        tJogador *jogadorTurno;
        if (turnoJogador1) {
            jogadorTurno = jogo->jogador1;
        } else {
            jogadorTurno = jogo->jogador2;
        }

        JogaJogador(jogadorTurno, jogo->tabuleiro);

        ImprimeTabuleiro(jogo->tabuleiro);

        turnoJogador1 = !turnoJogador1;
    }
}

int AcabouJogo(tJogo *jogo) {
    if (VenceuJogador(jogo->jogador1, jogo->tabuleiro)) {
        printf("JOGADOR %d Venceu!\n", ID_JOGADOR_1);
        return 1;
    }

    if (VenceuJogador(jogo->jogador2, jogo->tabuleiro)) {
        printf("JOGADOR %d Venceu!\n", ID_JOGADOR_2);
        return 1;
    }

    if (!TemPosicaoLivreTabuleiro(jogo->tabuleiro)) {
        printf("Sem vencedor!\n");
        return 1;
    }

    return 0;
}

int ContinuaJogo(void) {
    printf("Jogar novamente? (s,n)\n");

    char resposta;
    scanf("%*[^ns]");
    scanf("%c", &resposta);
    getchar();

    return resposta == 's';
}

void DestroiJogo(tJogo *jogo) {
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    DestroiTabuleiro(jogo->tabuleiro);
    free(jogo);
}
