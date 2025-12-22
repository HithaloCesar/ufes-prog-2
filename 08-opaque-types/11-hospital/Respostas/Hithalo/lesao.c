#include "lesao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Lesao {
    char cartaoSus[MAX_CARTAO_LES];
    char id[MAX_ID_LES];
    char diagnostico[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int malignidade;
};

Lesao *criaLesao(char *cartao, char *id, char *diag, char *regiao, int malig) {
    Lesao *lesao = malloc(sizeof(*lesao));

    strcpy(lesao->cartaoSus, cartao);
    strcpy(lesao->id, id);
    strcpy(lesao->diagnostico, diag);
    strcpy(lesao->regiao, regiao);
    lesao->malignidade = malig;

    return lesao;
}

Lesao *lerLesao(void) {
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
    getchar();

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
    free(l);
}
