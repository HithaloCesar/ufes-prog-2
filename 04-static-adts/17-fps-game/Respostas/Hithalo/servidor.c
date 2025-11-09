#include "servidor.h"
#include <stdio.h>

Servidor leRegistrosServidor(void) {
    Servidor s;
    s.nPartidas = 0;

    int idPartida;
    while (scanf("%d", &idPartida) == 1 && idPartida != -1) {
        s.partidas[s.nPartidas++] = leRegistro(idPartida);
    }

    return s;
}

Jogador buscaDadosJogadorServidor(Servidor s, int idJog) {
    Jogador jogador = inicializaJogador(-1);

    for (int i = 0; i < s.nPartidas; i++) {
        Jogador j = buscaJogadorRegistro(s.partidas[i], idJog);
        if (getIdJogador(j) != -1) {
            jogador = atualizaJogador(
                jogador,
                getIdJogador(j),
                getKillsJogador(j),
                getDeathsJogador(j),
                getAssistsJogador(j)
            );
        }
    }

    return jogador;
}

void criaRelatorioServidor(Servidor s) {
    int numRelatorios;
    scanf("%d", &numRelatorios);

    for (int i = 0; i < numRelatorios; i++) {
        int jogadorId;
        scanf("%d", &jogadorId);

        Jogador j = buscaDadosJogadorServidor(s, jogadorId);

        if (getIdJogador(j) == -1) {
            printf("Jogador %d: -\n", jogadorId);
        } else {
            printaJogador(j);
        }
    }
}
