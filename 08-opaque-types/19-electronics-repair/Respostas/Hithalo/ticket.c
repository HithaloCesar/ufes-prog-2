#include "ticket.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SITUACAO_PENDENTE "PENDENTE"
#define SITUACAO_CONCLUIDO "CONCLUIDO"

struct tic_str {
    char nome[MAXNOMETICKET];
    int codigo;
    char descricao[MAXDESCRICAOTICKET];
    char situacao[MAXSITUACAOTICKET];
};

tTicket *criaTicket(char *nome, int codigo, char *descricao) {
    tTicket *t = malloc(sizeof(*t));

    strcpy(t->situacao, SITUACAO_PENDENTE);
    strcpy(t->nome, nome);
    strcpy(t->descricao, descricao);
    t->codigo = codigo;

    return t;
}

tTicket *leTicket() {
    char nome[MAXNOMETICKET];
    int codigo;
    char descricao[MAXDESCRICAOTICKET];

    scanf(" %[^\n]", nome);
    scanf("%d", &codigo);
    scanf(" %[^\n]", descricao);
    getchar();

    return criaTicket(nome, codigo, descricao);
}

void alteraSituacaoTicket(tTicket *t) {
    strcpy(t->situacao, SITUACAO_CONCLUIDO);
}

int comparaTicket(tTicket *t, int codigo) {
    return t->codigo == codigo;
}

char *retornaNomeTicket(tTicket *t) {
    return t->nome;
}

int estaPendenteTicket(tTicket *t) {
    return !strcmp(t->situacao, SITUACAO_PENDENTE);
}

void imprimeTicket(tTicket *t) {
    printf("======================\n");
    printf("Nome: %s\n", t->nome);
    printf("Codigo: %d\n", t->codigo);
    printf("Situacao: %s\n", t->situacao);
    printf("Descricao: %s\n", t->descricao);
}

void destroiTicket(tTicket *t) {
    free(t);
}
