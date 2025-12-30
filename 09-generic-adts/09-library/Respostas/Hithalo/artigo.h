#ifndef ARTIGO_H
#define ARTIGO_H

#define ARTIGO_MAX_TAM_TITULO 100
#define ARTIGO_MAX_TAM_JORNAL 100
#define ARTIGO_MAX_TAM_AUTOR 100

typedef struct Artigo Artigo;

Artigo *criarArtigo(char *titulo, char *autor, char *editora, int ano, int numPaginas);

Artigo *lerArtigo();

int compararAutorArtigo(void *dado, void *chave);

int compararAnoArtigo(void *dado, void *chave);

void desalocarArtigo(void *dado);

void imprimirArtigo(void *dado);

#endif
