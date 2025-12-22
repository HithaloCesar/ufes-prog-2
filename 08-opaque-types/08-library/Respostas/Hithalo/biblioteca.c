#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Biblioteca {
    tLivros **livros;
    int qtdLivros;
    int tamLivros;
};

tBiblioteca* InicializarBiblioteca(void) {
    tBiblioteca *b = calloc(1, sizeof(*b));

    return b;
}

void ApagaBiblioteca(tBiblioteca* biblioteca) {
    for (int i = 0; i < biblioteca->qtdLivros; i++) {
        ApagaLivro(biblioteca->livros[i]);
    }
    free(biblioteca->livros);
    free(biblioteca);
}

void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro) {
    if (biblioteca->qtdLivros == biblioteca->tamLivros) {
        if (biblioteca->tamLivros == 0) {
            biblioteca->tamLivros = NUM_INICIAL_LIVROS;
        } else {
            biblioteca->tamLivros *= 2;
        }
        biblioteca->livros = realloc(
            biblioteca->livros,
            biblioteca->tamLivros * sizeof(*biblioteca->livros)
        );
    }
    biblioteca->livros[biblioteca->qtdLivros++] = livro;
    printf("Livro adicionado com sucesso!\n");
}

void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo) {
    for (int i = 0; i < biblioteca->qtdLivros; i++) {
        if (VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo) == 0) {
            ApagaLivro(biblioteca->livros[i]);
            for (int j = i; j < biblioteca->qtdLivros - 1; j++) {
                biblioteca->livros[j] = biblioteca->livros[j + 1];
            }
            biblioteca->qtdLivros--;
            printf("Livro removido com sucesso!\n");
            return;
        }
    }
    printf("Livro nao encontrado na biblioteca.\n");
}

int VerificaTituloDoLivroNaBiblioteca(tLivros *livro, char* titulo) {
    return strcmp(getTitulo(livro), titulo);
}

void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca) {
    if (biblioteca->qtdLivros == 0) {
        printf("A biblioteca esta vazia!\n");
        return;
    }

    putchar('\n');
    printf("Lista de Livros na Biblioteca:\n");
    for (int i = 0; i < biblioteca->qtdLivros; i++) {
        ImprimeLivro(biblioteca->livros[i]);
    }
}
