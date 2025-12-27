#include "brasileirao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _BRA {
    tTabela *tabela;
    int qtdTimes;
    int qtdRodadas;
    float valorPremio;
};

BRA *CriaCamp(void) {
    BRA *br = calloc(1, sizeof(*br));

    puts("Insira o num de times, rodadas e premio total:");
    scanf("%d %d %f", &br->qtdTimes, &br->qtdRodadas, &br->valorPremio);
    getchar();

    br->tabela = CriaTabela(br->qtdTimes);

    return br;
}

void RealizaRodada(BRA *br) {
    int qtdPartidas = br->qtdTimes / 2;

    for (int i = 0; i < qtdPartidas; i++) {
        char t1Nome[MAX_TIME_NOME + 1];
        char t2Nome[MAX_TIME_NOME + 1];
        int t1Gols, t2Gols;
        scanf("%s %d x %d %s", t1Nome, &t1Gols, &t2Gols, t2Nome);
        getchar();

        tTime *t1 = ObtemTimeTabela(br->tabela, t1Nome);
        tTime *t2 = ObtemTimeTabela(br->tabela, t2Nome);

        if (t1Gols > t2Gols) {
            AtualizaVitorias(t1);
            AtualizaDerrotas(t2);
        } else if (t1Gols < t2Gols) {
            AtualizaDerrotas(t1);
            AtualizaVitorias(t2);
        } else {
            AtualizaEmpates(t1);
            AtualizaEmpates(t2);
        }

        AtualizaGolsMarcados(t1, t1Gols);
        AtualizaGolsSofridos(t1, t2Gols);

        AtualizaGolsMarcados(t2, t2Gols);
        AtualizaGolsSofridos(t2, t1Gols);
    }
}

static void ImprimeMenu(void) {
    puts("Menu:");
    puts("C - Continuar");
    puts("R - Retirar 2 times e seguir");
    puts("F - Finalizar");
}

void RealizaCamp(BRA *br) {
    for (int i = 0; i < br->qtdRodadas; i++) {
        ImprimeMenu();

        char operacao;
        scanf(" %c", &operacao);
        getchar();

        switch (operacao) {
            case 'C': {
                RealizaRodada(br);
                break;
            }
            case 'R': {
                RemoveTimesCamp(br);
                RealizaRodada(br);
                break;
            }
            case 'F': {
                return;
            }
        }

        if (br->qtdTimes <= 0) {
            return;
        }

        OrdenaTabela(br->tabela);
        ImprimeTabela(br->tabela);
    }
}

void RemoveTimesCamp(BRA *br) {
    puts("Times a serem retirados:");

    char time1[MAX_TIME_NOME + 1], time2[MAX_TIME_NOME + 1];
    scanf("%s %s", time1, time2);
    getchar();

    RemoveTimeTabela(br->tabela, time1);
    RemoveTimeTabela(br->tabela, time2);
    br->qtdTimes -= 2;

    printf(
        "Os times %s e %s se retiraram do campeonato\n",
        time1,
        time2
    );
}

void DesalocaCamp(BRA *br) {
    DesalocaTabela(br->tabela);
    free(br);
}

void FinalizaCamp(BRA *br) {
    if (br->qtdTimes > 0) {
        puts("Esta foi a tabela final:");
        ImprimeTabela(br->tabela);
    }

    ImprimePremiacao(br->tabela, br->valorPremio);
    puts("Fim do campeonato");

    DesalocaCamp(br);
}
