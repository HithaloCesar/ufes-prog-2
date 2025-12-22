#include "livro.h"
#include <stdlib.h>
#include <stdio.h>

struct Livros {
    char *titulo;
    char *autor;
    int ano;
};

tLivros *CriaLivro(void) {
    tLivros *l = calloc(1, sizeof(*l));

    return l;
}

void LerLivro(tLivros *livro) {
    scanf(" %m[^\n]", &livro->titulo);
    scanf(" %m[^\n]", &livro->autor);
    scanf("%d", &livro->ano);
    getchar();
}

void ImprimeLivro(tLivros *livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->ano);
    putchar('\n');
}

char *getTitulo(tLivros *livro) {
    return livro->titulo;
}

void ApagaLivro(tLivros *livro) {
    free(livro->titulo);
    free(livro->autor);
    free(livro);
}
