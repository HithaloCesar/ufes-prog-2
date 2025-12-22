#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

typedef enum {
    OPCAO_ADICIONAR_LIVRO = 1,
    OPCAO_REMOVER_LIVRO,
    OPCAO_LISTAR_LIVROS
} tOpcao;

int main(void) {
    tBiblioteca *b = InicializarBiblioteca();

    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);
    getchar();

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");

    for (int i = 0; i < qtdOperacoes; i++) {
        int opcao;
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case OPCAO_ADICIONAR_LIVRO: {
                tLivros *l = CriaLivro();
                LerLivro(l);
                AdicionarLivroNaBiblioteca(b, l);
                break;
            }
            case OPCAO_REMOVER_LIVRO: {
                char *titulo;
                scanf(" %m[^\n]", &titulo);
                getchar();
                RemoverLivroDaBiblioteca(b, titulo);
                free(titulo);
                break;
            }
            case OPCAO_LISTAR_LIVROS: {
                ListarLivrosDaBiblioteca(b);
                break;
            }
            default: {
                printf("Operacao invalida!\n");
                ApagaBiblioteca(b);
                return EXIT_FAILURE;
                break;
            }
        }
    }

    ApagaBiblioteca(b);

    return EXIT_SUCCESS;
}
