#include "tAmbiente.h"

#include <stdlib.h>
#include <string.h>

#define AMBIENTE_NUM_COLUNAS 10
#define AMBIENTE_NUM_LINHAS 10

struct posicao {
    int linha;
    int coluna;
};

struct ambiente {
    char mapa[AMBIENTE_NUM_LINHAS][AMBIENTE_NUM_COLUNAS];
    struct posicao posJogador;
};

tAmbiente *criaAmbiente() {
    tAmbiente *amb = calloc(1, sizeof(*amb));

    char mapa[AMBIENTE_NUM_LINHAS][AMBIENTE_NUM_COLUNAS] = {
        {'\0', 'o', 't', '\0', '\0', 'g', '\0', '\0', '\0', 'o'},
        {'o', '\0', 'o', 'g', '\0', '\0', '\0', 't', 't', '\0'},
        {'-', '|', 'g', 'g', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'t', '\0', '\0', 'g', '\0', '\0', '\0', '\0', '\0', 'g'},
        {'g', 'o', '\0', '-', 'o', '\0', '\0', '\0', '-', 't'},
        {'o', '|', 'g', '\0', '\0', '\0', '\0', '\0', '|', 'o'},
        {'|', 'g', 'g', '|', 't', 't', 'o', 'g', '\0', 'g'},
        {'t', '\0', 'o', 'g', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'t', 'g', '\0', 'g', '\0', '\0', '\0', '|', '-', 'o'},
        {'-', '\0', '\0', '\0', '\0', '-', '-', 't', '\0', '\0'},
    };

    memcpy(amb->mapa, mapa, AMBIENTE_NUM_LINHAS * AMBIENTE_NUM_COLUNAS);

    return amb;
}

void liberaAmbiente(tAmbiente *amb) {
    free(amb);
}

char retornaSituacaoPosicao(tAmbiente *amb, int linha, int coluna) {
    return amb->mapa[linha][coluna];
}

void retornaPosicaoAtual(tAmbiente *amb, int *linha, int *coluna) {
    *linha = amb->posJogador.linha;
    *coluna = amb->posJogador.coluna;
}

void alteraConteudo(tAmbiente *amb, int linha, int coluna, char novoConteudo) {
    amb->mapa[linha][coluna] = novoConteudo;
}

void alteraPosicaoJogador(tAmbiente *amb, int linha, int coluna) {
    amb->posJogador.linha = linha;
    amb->posJogador.coluna = coluna;
}
