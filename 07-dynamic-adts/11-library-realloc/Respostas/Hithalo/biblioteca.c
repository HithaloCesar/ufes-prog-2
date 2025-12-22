#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tBiblioteca *InicializarBiblioteca(void) {
    tBiblioteca *b = calloc(1, sizeof(*b));

    return b;
}

void ApagaBiblioteca(tBiblioteca *b) {
    for (int i = 0; i < b->tamanho; i++) {
        ApagaLivro(b->livros[i]);
    }

    free(b->livros);
    free(b);
}

void AdicionarLivroNaBiblioteca(tBiblioteca *b, tLivros *l) {
    if (b->tamanho == b->tam_max_atual) {
        if (b->tam_max_atual == 0) {
            b->tam_max_atual = NUM_INICIAL_LIVROS;
        } else {
            b->tam_max_atual *= 2;
        }
        b->livros = realloc(b->livros, b->tam_max_atual * sizeof(*b->livros));
    }

    b->livros[b->tamanho++] = l;
    printf("Livro adicionado com sucesso!\n");
}

void RemoverLivroDaBiblioteca(tBiblioteca *b, char *titulo) {
    for (int i = 0; i < b->tamanho; i++) {
        if (VerificaTituloDoLivroNaBiblioteca(b->livros[i], titulo) == 0) {
            ApagaLivro(b->livros[i]);
            for (int j = i; j < b->tamanho - 1; j++) {
                b->livros[j] = b->livros[j + 1];
            }
            b->tamanho--;
            printf("Livro removido com sucesso!\n");
            return;
        }
    }

    printf("Livro nao encontrado na biblioteca.\n");
}

int VerificaTituloDoLivroNaBiblioteca(tLivros *l, char* titulo) {
    return strcmp(l->titulo, titulo);
    // Parece ser necessário acessar um campo de l...
}

void ListarLivrosDaBiblioteca(tBiblioteca *b) {
    if (b->tamanho == 0) {
        printf("A biblioteca esta vazia!\n");
        return;
    }

    putchar('\n');
    printf("Lista de Livros na Biblioteca:\n");
    for (int i = 0; i < b->tamanho; i++) {
        ImprimeLivro(b->livros[i]);
    }
}
