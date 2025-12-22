#include "tecnico.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXTICKETSINICIAL 1

struct str_tec {
    char nome[MAXNOMETECNICO];
    char id[MAXIDTECNICO];
    tTicket **tickets;
    int qtdTickets;
    int maxTickets;
};

tTecnico *criaTecnico(char *nome, char *id) {
    tTecnico *t = calloc(1, sizeof(*t));

    t->tickets = calloc(MAXTICKETSINICIAL, sizeof(*t->tickets));

    t->maxTickets = MAXTICKETSINICIAL;
    t->qtdTickets = 0;
    strcpy(t->nome, nome);
    strcpy(t->id, id);

    return t;
}

tTecnico *leTecnico() {
    char nome[MAXNOMETECNICO];
    char id[MAXIDTECNICO];
    scanf(" %[^\n]", nome);
    scanf(" %[^\n]", id);
    getchar();

    return criaTecnico(nome, id);
}

void atribuiTicket(tTecnico *tec, tTicket *tic) {
    if (tec->qtdTickets == tec->maxTickets) {
        printf("TECNICO SOBRECARREGADO\n");
        destroiTicket(tic);
        tic = NULL;
        return;
    }

    tec->tickets[tec->qtdTickets++] = tic;
}

void aumentaCargaTecnico(tTecnico *tec) {
    tec->maxTickets *= 2;
    tec->tickets = realloc(
        tec->tickets, tec->maxTickets * sizeof(*tec->tickets)
    );
}

void alteraSituacaoTicketTecnico(tTecnico *tec, int codigo) {
    for (int i = 0; i < tec->qtdTickets; i++) {
        if (comparaTicket(tec->tickets[i], codigo)) {
            alteraSituacaoTicket(tec->tickets[i]);
            return;
        }
    }
}

int quantidadeTicketsPendentes(tTecnico *t) {
    int qtdTicketsPendentes = 0;
    for (int i = 0; i < t->qtdTickets; i++) {
        if (estaPendenteTicket(t->tickets[i])) {
            qtdTicketsPendentes++;
        }
    }

    return qtdTicketsPendentes;
}

int comparaTecnico(tTecnico *t, char* id) {
    return !strcmp(t->id, id);
}

char *retornaNomeTecnico(tTecnico *t) {
    return t->nome;
}

void imprimeTecnico(tTecnico *t) {
    printf("Ficha do Tecnico #####\n");
    printf("Nome: %s\n", t->nome);
    printf("Id: %s\n", t->id);
    printf("Tickets atribuidos:\n");
    for (int i = 0; i < t->qtdTickets; i++) {
        imprimeTicket(t->tickets[i]);
    }
}

void destroiTecnico(tTecnico *t) {
    for (int i = 0; i < t->qtdTickets; i++) {
        destroiTicket(t->tickets[i]);
    }

    free(t->tickets);
    free(t);
}
