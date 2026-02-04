#include "tEventoMovimento.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define AMBIENTE_NUM_COLUNAS 10
#define AMBIENTE_NUM_LINHAS 10
#define MOVIMENTO_MAX_CARACTERES_ACEITOS 4

struct eventomovimento {
    char caracteresAceitos[MOVIMENTO_MAX_CARACTERES_ACEITOS];
};

tEventoMovimento* criaEventoMovimento(char *caracteresAceitos) {
    tEventoMovimento *eve = calloc(1, sizeof(*eve));

    memcpy(
        eve->caracteresAceitos,
        caracteresAceitos,
        MOVIMENTO_MAX_CARACTERES_ACEITOS
    );

    return eve;
}

void liberaEventoMovimento(void* eve) {
    free(eve);
}

void processaEventoMovimento(tAmbiente *amb, void *eve, char c) {
    tEventoMovimento *evMov = (tEventoMovimento *)eve;

    int novaLinhaJogador = 0;
    int novaColunaJogador = 0;
    retornaPosicaoAtual(amb, &novaLinhaJogador, &novaColunaJogador);

    if (c == evMov->caracteresAceitos[0]) {
        novaLinhaJogador--;
    } else if (c == evMov->caracteresAceitos[1]) {
        novaColunaJogador--;
    } else if (c == evMov->caracteresAceitos[2]) {
        novaLinhaJogador++;
    } else if (c == evMov->caracteresAceitos[3]) {
        novaColunaJogador++;
    }

    if (novaLinhaJogador < 0
        || novaLinhaJogador >= AMBIENTE_NUM_LINHAS
        || novaColunaJogador < 0
        || novaColunaJogador >= AMBIENTE_NUM_COLUNAS
    ) {
        puts("MOVIMENTO INVALIDO POIS SAI DO MAPA!");
        return;
    }

    char alvo = retornaSituacaoPosicao(
        amb,
        novaLinhaJogador,
        novaColunaJogador
    );
    if (alvo != '\0' && alvo != '0') {
        puts("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!");
        return;
    }

    alteraPosicaoJogador(amb, novaLinhaJogador, novaColunaJogador);
    printf("MOVIMENTO PARA POSICAO (%d,%d)\n", novaLinhaJogador, novaColunaJogador);
}

int identificaEventoMovimento(void *eve, char c) {
    tEventoMovimento *evMov = (tEventoMovimento *)eve;

    for (int i = 0; i < MOVIMENTO_MAX_CARACTERES_ACEITOS; i++) {
        if (c == evMov->caracteresAceitos[i]) {
            return 1;
        }
    }

    return 0;
}
