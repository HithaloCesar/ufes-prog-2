#include "livro.h"
#include <stdlib.h>
#include <stdio.h>

tLivros *CriaLivro(void) {
    tLivros *livro = calloc(1, sizeof(*livro));

    return livro;
}

void LerLivro(tLivros *livro) {
    scanf(" %m[^\n]", &livro->titulo);
    scanf(" %m[^\n]", &livro->autor);
    scanf("%d", &livro->anoPublicacao);
    getchar();
}

void ImprimeLivro(tLivros *livro) {
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->anoPublicacao);
    putchar('\n');
}

void ApagaLivro(tLivros *livro) {
    free(livro->titulo);
    free(livro->autor);
    free(livro);
}
