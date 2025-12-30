#include "movel.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NOME_MAX_LEN 30

struct Movel {
    char nome[NOME_MAX_LEN + 1];
};

tMovel *CriaMovel(char *nome) {
    tMovel *m = calloc(1, sizeof(*m));

    strcpy(m->nome, nome);

    return m;
}

void DestroiMovel(tMovel *m) {
    free(m);
}

tMovel *LeMovel(void) {
    char nome[NOME_MAX_LEN + 1];
    scanf(" %[^\n]", nome);
    getchar();

    tMovel *m = CriaMovel(nome);

    return m;
}

void ImprimeMovel(tMovel *m) {
    printf("%s\n", m->nome);
}
