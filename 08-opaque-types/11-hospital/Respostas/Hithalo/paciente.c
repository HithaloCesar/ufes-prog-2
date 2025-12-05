#include "paciente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Paciente {
    char *nome;
    char *cartaoSus;
    char genero;
    Data *dataNasc;
    Lesao **lesoes;
    size_t tamanhoLesoes;
    int qtdLesoes;
};

Paciente *criaPaciente(char *nome,
    char *cartaoSus,
    char genero,
    Data *dataNasc
) {
    Paciente *paciente = malloc(sizeof(*paciente));
    if (paciente == NULL) {
        return NULL;
    }

    paciente->nome = malloc(MAX_NOME_PAC * sizeof(paciente->nome) + 1);
    if (paciente->nome == NULL) {
        free(paciente);
        return NULL;
    }

    paciente->cartaoSus = malloc(
        MAX_CARTAO_SUS * sizeof(*paciente->cartaoSus) + 1
    );
    if (paciente->cartaoSus == NULL) {
        free(paciente->nome);
        free(paciente);
        return NULL;
    }

    paciente->lesoes = malloc(MAX_LESOES * sizeof(*paciente->lesoes));
    if (paciente->lesoes == NULL) {
        free(paciente->nome);
        free(paciente->cartaoSus);
        free(paciente);
        return NULL;
    }

    strcpy(paciente->nome, nome);
    strcpy(paciente->cartaoSus, cartaoSus);
    paciente->genero = genero;
    paciente->dataNasc = dataNasc;
    paciente->qtdLesoes = 0;
    paciente->tamanhoLesoes = MAX_LESOES;

    return paciente;
}

Paciente *lerPaciente() {
    char nome[MAX_NOME_PAC + 1];
    char cartaoSus[MAX_CARTAO_SUS + 1];
    char genero;

    scanf(" %[^\n]", nome);
    Data *dataNasc = lerData();
    scanf(" %[^\n]", cartaoSus);
    scanf(" %c", &genero);

    return criaPaciente(nome, cartaoSus, genero, dataNasc);
}

void adicionaLesaoPaciente(Paciente *p, Lesao *l) {
    if (p->qtdLesoes == p->tamanhoLesoes) {
        Lesao **novoLesoes;
        p->tamanhoLesoes += MAX_LESOES;
        novoLesoes = realloc(p->lesoes, p->tamanhoLesoes * sizeof(*p->lesoes));
        if (novoLesoes == NULL) {
            return;
        }
        p->lesoes = novoLesoes;
    }
    p->lesoes[p->qtdLesoes++] = l;
}

int calculaIdadePaciente(Paciente *p, Data *dataBase) {
    return diferencaAnoData(p->dataNasc, dataBase);
}

char *getCartaoSusPaciente(Paciente *p) {
    return p->cartaoSus;
}

int getNumLesoesPaciente(Paciente *p) {
    return p->qtdLesoes;
}

int qtdLesoesCirurgicasPaciente(Paciente *p) {
    int qtdCirurgias = 0;
    for (int i = 0; i < p->qtdLesoes; i++) {
        if (verificaCirurgicaLesao(p->lesoes[i])) {
            qtdCirurgias++;
        }
    }

    return qtdCirurgias;
}

void imprimePaciente(Paciente *p) {
    if (getNumLesoesPaciente(p) <= 0) {
        return;
    }

    printf("- %s - ", p->nome);
    for (int i = 0 ; i < p->qtdLesoes; i++) {
        imprimeIdLesao(p->lesoes[i]);
        putchar(' ');
    }
    putchar('\n');
}

void liberaPaciente(Paciente *p) {
    free(p->nome);
    free(p->cartaoSus);
    liberaData(p->dataNasc);
    for (int i = 0; i < p->qtdLesoes; i++) {
        liberaLesao(p->lesoes[i]);
    }
    free(p->lesoes);
    free(p);
}
