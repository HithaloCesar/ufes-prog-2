#include "registro.h"
#include <stdio.h>

Registro leRegistro(int idPartida) {
    Registro r;
    r.idPartida = idPartida;

    int idJogador;
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++) {
        scanf("%d: ", &idJogador);
        r.jogadores[i] = leJogador(idJogador);
    }

    return r;
}

Jogador buscaJogadorRegistro(Registro r, int idJog) {
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++) {
        if (getIdJogador(r.jogadores[i]) == idJog) {
            return r.jogadores[i];
        }
    }

    return inicializaJogador(-1);
}
