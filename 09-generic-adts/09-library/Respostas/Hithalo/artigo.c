#include "artigo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Artigo {
    char titulo[ARTIGO_MAX_TAM_TITULO + 1];
    char autor[ARTIGO_MAX_TAM_AUTOR + 1];
    char jornal[ARTIGO_MAX_TAM_JORNAL + 1];
    int ano;
    int numPaginas;
};

Artigo *criarArtigo(char *titulo, char *autor, char *jornal, int ano, int numPaginas) {
    Artigo *artigo = calloc(1, sizeof(*artigo));

    strcpy(artigo->titulo, titulo);
    strcpy(artigo->autor, autor);
    strcpy(artigo->jornal, jornal);
    artigo->ano = ano;
    artigo->numPaginas = numPaginas;

    return artigo;
}

Artigo *lerArtigo() {
    char titulo[ARTIGO_MAX_TAM_TITULO + 1];
    char autor[ARTIGO_MAX_TAM_AUTOR + 1];
    char jornal[ARTIGO_MAX_TAM_JORNAL + 1];
    int ano;
    int numPaginas;

    scanf(" %[^\n]", titulo);
    scanf(" %[^\n]", autor);
    scanf(" %[^\n]", jornal);
    scanf("%d", &ano);
    scanf("%d", &numPaginas);

    Artigo *artigo = criarArtigo(titulo, autor, jornal, ano, numPaginas);

    return artigo;
}

int compararAutorArtigo(void *dado, void *chave) {
    Artigo *artigo = (Artigo *)dado;
    char *autor = (char *)chave;

    return !strcmp(artigo->autor, autor);
}

int compararAnoArtigo(void *dado, void *chave) {
    Artigo *artigo = (Artigo *)dado;
    int *ano = (int *)chave;

    return artigo->ano == *ano;
}

void desalocarArtigo(void *dado) {
    free(dado);
}

void imprimirArtigo(void *dado) {
    Artigo *artigo = (Artigo *)dado;

    puts("- - - Artigo - - -");
    printf("Titulo: %s\n", artigo->titulo);
    printf("Autor: %s\n", artigo->autor);
    printf("Jornal: %s\n", artigo->jornal);
    printf("Ano: %d\n", artigo->ano);
    printf("Num. Paginas: %d\n", artigo->numPaginas);
    puts("- - - - - - - - -");
}
