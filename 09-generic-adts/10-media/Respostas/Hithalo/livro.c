#include "livro.h"
#include <stdlib.h>
#include <stdio.h>

struct Livro {
    char titulo[MAXTAM_STRINGS + 1];
    char autor[MAXTAM_STRINGS + 1];
    char genero[MAXTAM_STRINGS + 1];
    char editora[MAXTAM_STRINGS + 1];
    int ano_de_publicacao;
};

Livro *livro_read_and_construct(void) {
    Livro *livro = calloc(1, sizeof(*livro));

    scanf(" %s", livro->titulo);
    scanf(" %s", livro->autor);
    scanf(" %s", livro->genero);
    scanf(" %s", livro->editora);
    scanf("%d", &livro->ano_de_publicacao);
    getchar();

    return livro;
}

void livro_print(void *l) {
    Livro *livro = (Livro *)l;

    puts("LIVRO");
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Genero: %s\n", livro->genero);
    printf("Editora: %s\n", livro->editora);
    printf("Ano: %d\n", livro->ano_de_publicacao);
}

void livro_destroy(void *l) {
    free(l);
}
