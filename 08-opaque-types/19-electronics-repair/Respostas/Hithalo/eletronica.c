#include "eletronica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct str_ele {
    char nome[QTDMAXNOMEELETRONICA];
    tTecnico **tecnicos;
    int qtdTecnicos;
};

tEletronica *criaEletronica(char *nome) {
    tEletronica *e = calloc(1, sizeof(*e));

    e->tecnicos = calloc(QTDMAXTECNICO, sizeof(*e->tecnicos));

    strcpy(e->nome, nome);

    return e;
}

void cadastraTecnico(tEletronica *e, tTecnico *t) {
    e->tecnicos[e->qtdTecnicos++] = t;
}

static tTecnico *BuscaTecnico(tEletronica *e, char *id) {
    for (int i = 0; i < e->qtdTecnicos; i++) {
        if (comparaTecnico(e->tecnicos[i], id)) {
            return e->tecnicos[i];
        }
    }

    return NULL;
}

void atribuiTicketEletronica(tEletronica *e, char *id, tTicket *t) {
    tTecnico *tecnico = BuscaTecnico(e, id);
    if (!tecnico) {
        printf("TECNICO NAO ENCONTRADO\n");
        destroiTicket(t);
        t = NULL;
        return;
    }

    atribuiTicket(tecnico, t);
}

void aumentaCargaTecnicoEletronica(tEletronica *e, char *id) {
    tTecnico *tecnico = BuscaTecnico(e, id);
    if (!tecnico) {
        printf("TECNICO NAO ENCONTRADO\n");
        return;
    }

    aumentaCargaTecnico(tecnico);
}

void alteraSituacaoTicketEletronica(tEletronica *e, int codigo) {
    for (int i = 0; i < e->qtdTecnicos; i++) {
        alteraSituacaoTicketTecnico(e->tecnicos[i], codigo);
    }
}

static tTecnico *BuscaTecnicoMaisPendencias(tEletronica *e) {
    if (e->qtdTecnicos == 0) {
        return NULL;
    }

    tTecnico *tecnicoMaisPendencias = e->tecnicos[0];
    int maxPendencias = quantidadeTicketsPendentes(tecnicoMaisPendencias);
    for (int i = 1; i < e->qtdTecnicos; i++) {
        int pendencias = quantidadeTicketsPendentes(e->tecnicos[i]);
        if (pendencias > maxPendencias) {
            tecnicoMaisPendencias = e->tecnicos[i];
            maxPendencias = pendencias;
        }
    }

    return tecnicoMaisPendencias;
}

void imprimeEletronica(tEletronica *e) {
    printf("Nome: %s\n", e->nome);
    printf("Tecnicos empregados:\n");
    for (int i = 0; i < e->qtdTecnicos; i++) {
        imprimeTecnico(e->tecnicos[i]);
    }

    printf("======================\n");

    tTecnico *tecnicoMaisPendencias = BuscaTecnicoMaisPendencias(e);
    if (!tecnicoMaisPendencias) {
        return;
    }

    printf(
        "Tecnico com maior numero de pendencias: %s\n",
        retornaNomeTecnico(tecnicoMaisPendencias)
    );
}

void destroiEletronica(tEletronica *e) {
    for (int i = 0; i < e->qtdTecnicos; i++) {
        destroiTecnico(e->tecnicos[i]);
    }

    free(e->tecnicos);
    free(e);
}
