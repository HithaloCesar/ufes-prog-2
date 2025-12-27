#include "tabela.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TIMES 20

#define MAX_TIMES_NO_PODIO 3

#define TRES_TIMES_PORCENTAGEM_1_LUGAR 0.5
#define TRES_TIMES_PORCENTAGEM_2_LUGAR 0.3
#define TRES_TIMES_PORCENTAGEM_3_LUGAR 0.2

#define DOIS_TIMES_PORCENTAGEM_1_LUGAR 0.6
#define DOIS_TIMES_PORCENTAGEM_2_LUGAR 0.4

struct _Tabela {
    tTime *times[MAX_TIMES];
    int qtdTimes;
};

static int ComparaTimes(const void *a, const void *b);

tTabela *CriaTabela(int numTimes) {
    tTabela *tabela = calloc(1, sizeof(*tabela));

    for (int i = 0; i < numTimes; i++) {
        tabela->times[tabela->qtdTimes++] = LeTime();
    }

    return tabela;
}

void DesalocaTabela(tTabela *tabela) {
    for (int i = 0; i < tabela->qtdTimes; i++) {
        DesalocaTime(tabela->times[i]);
    }

    free(tabela);
}

void OrdenaTabela(tTabela *tabela) {
    qsort(
        tabela->times,
        tabela->qtdTimes,
        sizeof(*tabela->times),
        ComparaTimes
    );
}

tTime *ObtemTimeTabela(tTabela *tabela, char *time) {
    for (int i = 0; i < tabela->qtdTimes; i++) {
        if (!strcmp(ObtemNomeTime(tabela->times[i]), time)) {
            return tabela->times[i];
        }
    }

    return NULL;
}

void RemoveTimeTabela(tTabela *tabela, char *time) {
    for (int i = 0; i < tabela->qtdTimes; i++) {
        if (!strcmp(ObtemNomeTime(tabela->times[i]), time)) {
            DesalocaTime(tabela->times[i]);

            for (int j = i; j < tabela->qtdTimes - 1; j++) {
                tabela->times[j] = tabela->times[j + 1];
            }

            tabela->qtdTimes--;
            tabela->times[tabela->qtdTimes] = NULL;

            return;
        }
    }
}

void ImprimePremiacao(tTabela *tabela, float valorPremio) {
    if (tabela->qtdTimes <= 0) {
        printf(
            "Premio de R$%.2f acumulado para a proxima edicao\n",
            valorPremio
        );
        return;
    }

    float premios[MAX_TIMES_NO_PODIO];
    if (tabela->qtdTimes >= 3) {
        premios[0] = valorPremio * TRES_TIMES_PORCENTAGEM_1_LUGAR;
        premios[1] = valorPremio * TRES_TIMES_PORCENTAGEM_2_LUGAR;
        premios[2] = valorPremio * TRES_TIMES_PORCENTAGEM_3_LUGAR;
    } else if (tabela->qtdTimes == 2) {
        premios[0] = valorPremio * DOIS_TIMES_PORCENTAGEM_1_LUGAR;
        premios[1] = valorPremio * DOIS_TIMES_PORCENTAGEM_2_LUGAR;
    } else {
        premios[0] = valorPremio;
    }

    int qtdTimesPodio = MAX_TIMES_NO_PODIO;
    if (tabela->qtdTimes < MAX_TIMES_NO_PODIO) {
        qtdTimesPodio = tabela->qtdTimes;
    }

    for (int i = 0; i < qtdTimesPodio; i++) {
        printf(
            "%dº lugar - %s: R$%.2f\n",
            i + 1, ObtemNomeTime(tabela->times[i]), premios[i]
        );
    }
}

void ImprimeTabela(tTabela *tabela) {
    puts("Classificação:");
    puts("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo");
    for (int i = 0; i < tabela->qtdTimes; i++) {
        ImprimeTime(tabela->times[i]);
    }
}

static int ComparaTimes(const void *a, const void *b) {
    return DesempataTimes(*(tTime**)a, *(tTime**)b);
}
