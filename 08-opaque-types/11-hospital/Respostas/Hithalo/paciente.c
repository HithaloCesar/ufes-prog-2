#include "paciente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Paciente {
    char nome[MAX_NOME_PAC];
    char cartaoSus[MAX_CARTAO_SUS];
    char genero;
    Data *dataNasc;
    Lesao *lesoes[MAX_LESOES];
    int numLesoes;
};

Paciente *criaPaciente(char *nome, char *cartao, char genero, Data *dataNasc) {
    Paciente *p = calloc(1, sizeof(*p));

    strcpy(p->nome, nome);
    strcpy(p->cartaoSus, cartao);
    p->genero = genero;
    p->dataNasc = dataNasc;

    return p;
}

Paciente *lerPaciente(void) {
    char nome[MAX_NOME_PAC];
    char cartaoSus[MAX_CARTAO_SUS];
    char genero;

    scanf(" %[^\n]", nome);
    getchar();
    Data *dataNasc = lerData();
    scanf(" %[^\n]", cartaoSus);
    scanf(" %c", &genero);
    getchar();

    return criaPaciente(nome, cartaoSus, genero, dataNasc);
}

void adicionaLesaoPaciente(Paciente *p, Lesao *l) {
    p->lesoes[p->numLesoes++] = l;
}

int calculaIdadePaciente(Paciente *p, Data *dataBase) {
    return diferencaAnoData(p->dataNasc, dataBase);
}

char *getCartaoSusPaciente(Paciente *p) {
    return p->cartaoSus;
}

int getNumLesoesPaciente(Paciente *p) {
    return p->numLesoes;
}

int qtdLesoesCirurgicasPaciente(Paciente *p) {
    int qtdLesoesCirurgicas = 0;
    for (int i = 0; i < p->numLesoes; i++) {
        if (verificaCirurgicaLesao(p->lesoes[i])) {
            qtdLesoesCirurgicas++;
        }
    }

    return qtdLesoesCirurgicas;
}

void imprimePaciente(Paciente *p) {
    if (p->numLesoes == 0) {
        return;
    }

    printf("- %s - ", p->nome);
    for (int i = 0; i < p->numLesoes; i++) {
        imprimeIdLesao(p->lesoes[i]);
        putchar(' ');
    }
    putchar('\n');
}

void liberaPaciente(Paciente *p) {
    for (int i = 0; i < p->numLesoes; i++) {
        liberaLesao(p->lesoes[i]);
    }
    liberaData(p->dataNasc);
    free(p);
}
