#include "time.h"
#include <stdlib.h>
#include <stdio.h>

struct _Time {
    char nome[MAX_TIME_NOME + 1];
    int qtdVitorias;
    int qtdEmpates;
    int qtdDerrotas;
    int qtdGolsMarcados;
    int qtdGolsSofridos;
};

tTime *LeTime(void) {
    tTime *t = calloc(1, sizeof(*t));

    scanf(" %s", t->nome);
    getchar();

    return t;
}

int ObtemVitorias(tTime *t) {
    return t->qtdVitorias;
}

int ObtemPartidas(tTime *t) {
    return t->qtdVitorias + t->qtdEmpates + t->qtdDerrotas;
}

int ObtemDerrotas(tTime *t) {
    return t->qtdDerrotas;
}

char *ObtemNomeTime(tTime *t) {
    return t->nome;
}

int ObtemSaldo(tTime *t) {
    return t->qtdGolsMarcados - t->qtdGolsSofridos;
}

void AtualizaVitorias(tTime *t) {
    t->qtdVitorias++;
}

void AtualizaEmpates(tTime *t) {
    t->qtdEmpates++;
}

void AtualizaDerrotas(tTime *t) {
    t->qtdDerrotas++;
}

void AtualizaGolsMarcados(tTime *t, int gols) {
    t->qtdGolsMarcados += gols;
}

void AtualizaGolsSofridos(tTime *t, int gols) {
    t->qtdGolsSofridos += gols;
}

int ObtemPontos(tTime *t) {
    return t->qtdVitorias * 3 + t->qtdEmpates;
}

int DesempataTimes(tTime *t1, tTime *t2) {
    int pontosT1 = ObtemPontos(t1);
    int pontosT2 = ObtemPontos(t2);

    if (pontosT1 != pontosT2) {
        return pontosT1 - pontosT2 > 0 ? -1 : 1;
    }

    if (t1->qtdVitorias != t2->qtdVitorias) {
        return t1->qtdVitorias - t2->qtdVitorias > 0 ? -1 : 1;
    }

    int saldoT1 = ObtemSaldo(t1);
    int saldoT2 = ObtemSaldo(t2);

    if (saldoT1 != saldoT2) {
        return saldoT1 - saldoT2 > 0 ? -1 : 1;
    }

    return 0;
}

void ImprimeTime(tTime *t) {
    int pontos = ObtemPontos(t);
    int saldo = ObtemSaldo(t);

    printf(
        "%-12s    | %02d | %02d | %02d | %02d | %+03d\n",
        t->nome,
        pontos,
        t->qtdVitorias,
        t->qtdDerrotas,
        t->qtdEmpates,
        saldo
    );
}

void DesalocaTime(tTime *t) {
    free(t);
}
