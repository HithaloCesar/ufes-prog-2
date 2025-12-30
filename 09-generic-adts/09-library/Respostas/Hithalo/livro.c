#include "livro.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[MAX_TAM_TITULO + 1];
    char autor[MAX_TAM_AUTOR + 1];
    char editora[MAX_TAM_EDITORA + 1];
    int ano;
};

Livro *criarLivro(char *titulo, char *autor, char *editora, int ano) {
    Livro *livro = calloc(1, sizeof(*livro));

    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);
    strcpy(livro->editora, editora);
    livro->ano = ano;

    return livro;
}

Livro *lerLivro() {
    char titulo[MAX_TAM_TITULO + 1];
    char autor[MAX_TAM_AUTOR + 1];
    char editora[MAX_TAM_EDITORA + 1];
    int ano;

    scanf(" %[^\n]", titulo);
    scanf(" %[^\n]", autor);
    scanf(" %[^\n]", editora);
    scanf("%d", &ano);

    Livro *livro = criarLivro(titulo, autor, editora, ano);

    return livro;
}

int compararAutorLivro(void *dado, void *chave) {
    Livro *livro = (Livro *)dado;
    char *autor = (char *)chave;

    return !strcmp(livro->autor, autor);
}

int compararAnoLivro(void *dado, void *chave) {
    Livro *livro = (Livro *)dado;
    int *ano = (char *)chave;

    return livro->ano == *ano;
}

void desalocarLivro(void *dado) {
    free(dado);
}

void imprimirLivro(void *dado) {
    Livro *livro = (Livro *)dado;

    puts("- - - Livro - - -");
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Editora: %s\n", livro->editora);
    printf("Ano: %d\n", livro->ano);
    puts("- - - - - - - - -");
}
