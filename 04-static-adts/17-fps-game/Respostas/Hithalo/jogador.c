#include "jogador.h"
#include <stdio.h>

Jogador inicializaJogador(int id) {
    Jogador j = {0};
    j.id = id;

    return j;
}

Jogador leJogador(int id) {
    Jogador j = inicializaJogador(id);
    scanf("%d %d %d", &j.kills, &j.deaths, &j.assists);

    return j;
}

float calculaKDA(Jogador j) {
    if (j.deaths == 0) {
        return j.kills + j.assists;
    }

    return (float)(j.kills + j.assists) / j.deaths;
}

Jogador atualizaJogador(Jogador j, int id, int k, int d, int a) {
    j.id = id;
    j.kills += k;
    j.deaths += d;
    j.assists += a;

    return j;
}

int getKillsJogador(Jogador j) {
    return j.kills;
}

int getDeathsJogador(Jogador j) {
    return j.deaths;
}

int getAssistsJogador(Jogador j) {
    return j.assists;
}

int getIdJogador(Jogador j) {
    return j.id;
}

void printaJogador(Jogador j) {
    j.valorKDA = calculaKDA(j);

    printf(
        "Jogador %d: %d/%d/%d (%.2f)\n",
        j.id, j.kills, j.deaths, j.assists, j.valorKDA
    );
}
