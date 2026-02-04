#include "tEventoClique.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "tAmbiente.h"

#define CLIQUE_MAX_CARACTERES_ACEITOS 3

struct eventoclique {
    char caracteresAceitos[CLIQUE_MAX_CARACTERES_ACEITOS];
    int linha;
    int coluna;
    bool selecionou;
};

tEventoClique* criaEventoClique(char *caracteresAceitos) {
    tEventoClique *eve = calloc(1, sizeof(*eve));

    memcpy(
        eve->caracteresAceitos,
        caracteresAceitos,
        CLIQUE_MAX_CARACTERES_ACEITOS
    );

    return eve;
}

void liberaEventoClique(void* eve) {
    free(eve);
}

void processaEventoClique(tAmbiente *amb, void *eve, char c) {
    tEventoClique *evClique = (tEventoClique *)eve;

    int linhaJogador = 0;
    int colunaJogador = 0;
    retornaPosicaoAtual(amb, &linhaJogador, &colunaJogador);

    if (c == 'L') {
        int linhaClique, colunaClique;
        scanf("%d %d", &linhaClique, &colunaClique);
        getchar();

        evClique->selecionou = false;

        int diff_linha_sqrd = (linhaJogador - linhaClique) * (linhaJogador - linhaClique);
        int diff_coluna_sqrd = (colunaJogador - colunaClique) * (colunaJogador - colunaClique);
        if (diff_linha_sqrd + diff_coluna_sqrd != 1) {
            puts("CLIQUE LONGE DA POSICAO ATUAL");
            return;
        }

        char c = retornaSituacaoPosicao(
            amb,
            linhaClique,
            colunaClique
        );

        if (c == '\0' || c == '0' || c == '|' || c == '-') {
            puts("CLIQUE ESQUERDO NAO SELECIONOU INIMIGO");
            return;
        }

        evClique->linha = linhaClique;
        evClique->coluna = colunaClique;
        evClique->selecionou = true;

        printf("INIMIGO %c SELECIONADO EM (%d,%d)\n",
            c,
            evClique->linha,
            evClique->coluna
        );
    } else if (c == 'R' || c == 'M') {
        char cliqueExtensoMeio[] = "DO MEIO";
        char cliqueExtensoDireito[] = "DIREITO";
        char *cliqueExtenso;
        if (c == 'R') {
            cliqueExtenso = cliqueExtensoDireito;
        } else if (c == 'M') {
            cliqueExtenso = cliqueExtensoMeio;
        }

        if (!evClique->selecionou) {
            printf("CLIQUE %s SEM ALVO\n", cliqueExtenso);
            return;
        }

        int diff_linha = linhaJogador - evClique->linha;
        int diff_linha_sqrd = diff_linha * diff_linha;
        int diff_coluna = colunaJogador - evClique->coluna;
        int diff_coluna_sqrd = diff_coluna * diff_coluna;
        if (diff_linha_sqrd + diff_coluna_sqrd != 1) {
            puts("ALVO LONGE DA POSICAO ATUAL");
            return;
        }

        char c = retornaSituacaoPosicao(
            amb,
            evClique->linha,
            evClique->coluna
        );

        printf("INIMIGO %c DA POSICAO (%d,%d) ELIMINADO COM CLIQUE %s\n",
            c,
            evClique->linha,
            evClique->coluna,
            cliqueExtenso
        );

        alteraConteudo(amb, evClique->linha, evClique->coluna, '\0');

        evClique->selecionou = false;
    }
}

int identificaEventoClique(void *eve, char c) {
    tEventoClique *evClique = (tEventoClique *)eve;

    for (int i = 0; i < CLIQUE_MAX_CARACTERES_ACEITOS; i++) {
        if (c == evClique->caracteresAceitos[i]) {
            return 1;
        }
    }

    return 0;
}
