#include "lesao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Lesao {
    char *cartaoSus;
    char *id;
    char *diagnostico;
    char *regiao;
    int malignidade;
};

Lesao *criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade) {
    Lesao *lesao = malloc(sizeof(*lesao));
    if (lesao == NULL) {
        return NULL;
    }

    lesao->cartaoSus = malloc(MAX_CARTAO_LES * sizeof(*lesao->cartaoSus) + 1);
    if (lesao->cartaoSus == NULL) {
        free(lesao);
        return NULL;
    }

    lesao->id = malloc(MAX_ID_LES * sizeof(*lesao->id) + 1);
    if (lesao->id == NULL) {
        free(lesao->cartaoSus);
        free(lesao);
        return NULL;
    }

    lesao->diagnostico = malloc(MAX_DIAG_LES * sizeof(*lesao->diagnostico) + 1);
    if (lesao->diagnostico == NULL) {
        free(lesao->cartaoSus);
        free(lesao->id);
        free(lesao);
        return NULL;
    }

    lesao->regiao = malloc(MAX_REG_LES * sizeof(*lesao->regiao) + 1);
    if (lesao->regiao == NULL) {
        free(lesao->cartaoSus);
        free(lesao->id);
        free(lesao->diagnostico);
        free(lesao);
        return NULL;
    }

    strcpy(lesao->cartaoSus, cartaoSus);
    strcpy(lesao->id, id);
    strcpy(lesao->diagnostico, diagnostico);
    strcpy(lesao->regiao, regiao);
    lesao->malignidade = malignidade;

    return lesao;
}

Lesao *lerLesao() {
    char cartaoSus[MAX_CARTAO_LES];
    char id[MAX_ID_LES];
    char diagnostico[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int malignidade;

    scanf(" %[^\n]", cartaoSus);
    scanf(" %[^\n]", id);
    scanf(" %[^\n]", diagnostico);
    scanf(" %[^\n]", regiao);
    scanf("%d", &malignidade);

    return criaLesao(cartaoSus, id, diagnostico, regiao, malignidade);
}

char *getCartaoSusLesao(Lesao *l) {
    return l->cartaoSus;
}

int verificaCirurgicaLesao(Lesao *l) {
    return l->malignidade > 50;
}

void imprimeIdLesao(Lesao *l) {
    printf("%s", l->id);
}

void liberaLesao(Lesao *l) {
    free(l->cartaoSus);
    free(l->id);
    free(l->diagnostico);
    free(l->regiao);
    free(l);
}
