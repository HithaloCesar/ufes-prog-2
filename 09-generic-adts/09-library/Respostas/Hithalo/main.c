#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "livro.h"
#include "artigo.h"
#include "secao.h"

enum Operacao {
    OPERACAO_ADICIONAR_LIVRO = 'L',
    OPERACAO_ADICIONAR_ARTIGO = 'A',
    OPERACAO_EXECUTAR_FUNCIONALIDADE = 'E',
    OPERACAO_FINALIZAR_PROGRAMA = 'F'
};

static void ExecutarFuncionalidade(Secao *secaoLivros, Secao *secaoArtigos);
static void ListarAutor(Secao *secaoLivros, Secao *secaoArtigos);
static void ListarAno(Secao *secaoLivros, Secao *secaoArtigos);

int main (void) {
    Secao *secaoLivros = criarSecao(desalocarLivro);
    Secao *secaoArtigos = criarSecao(desalocarArtigo);

    bool continuarExecucao = true;
    while (continuarExecucao) {
        char operacao;
        scanf(" %c", &operacao);
        getchar();

        switch (operacao) {
            case OPERACAO_ADICIONAR_LIVRO: {
                Livro *livro = lerLivro();
                addItemSecao(secaoLivros, livro);
                break;
            }
            case OPERACAO_ADICIONAR_ARTIGO: {
                Artigo *artigo = lerArtigo();
                addItemSecao(secaoArtigos, artigo);
                break;
            }
            case OPERACAO_EXECUTAR_FUNCIONALIDADE: {
                ExecutarFuncionalidade(secaoLivros, secaoArtigos);
                break;
            }
            case OPERACAO_FINALIZAR_PROGRAMA: {
                continuarExecucao = false;
                break;
            }
        }
    }

    desalocarSecao(secaoLivros);
    desalocarSecao(secaoArtigos);

    return EXIT_SUCCESS;
}

static void ExecutarFuncionalidade(Secao *secaoLivros, Secao *secaoArtigos) {
    char *funcionalidade;
    scanf(" %m[^\n]", &funcionalidade);

    if (!strcmp(funcionalidade, "LISTAR ACERVO")) {
        puts("- - - LISTA DE TODOS OS ITENS DA BIBLIOTECA - - -");
        imprimirItensSecao(secaoLivros, imprimirLivro);
        imprimirItensSecao(secaoArtigos, imprimirArtigo);
    } else if (!strcmp(funcionalidade, "LISTAR LIVROS")) {
        puts("- - - LISTA DE TODOS OS LIVROS DA BIBLIOTECA - - -");
        imprimirItensSecao(secaoLivros, imprimirLivro);
    } else if (!strcmp(funcionalidade, "LISTAR ARTIGOS")) {
        puts("- - - LISTA DE TODOS OS ARTIGOS DA BIBLIOTECA - - -");
        imprimirItensSecao(secaoArtigos, imprimirArtigo);
    } else if (!strcmp(funcionalidade, "LISTAR AUTOR")) {
        ListarAutor(secaoLivros, secaoArtigos);
    } else if (!strcmp(funcionalidade, "LISTAR ANO")) {
        ListarAno(secaoLivros, secaoArtigos);
    }

    free(funcionalidade);
}

static void ListarAutor(Secao *secaoLivros, Secao *secaoArtigos) {
    char *autor;
    scanf(" %m[^\n]", &autor);
    getchar();
    puts("- - - LISTA DE TODOS OS ITENS DE UM AUTOR - - -");
    printf("Nome do autor: %s\n", autor);
    imprimirItensPorChaveSecao(
        secaoLivros, autor, compararAutorLivro, imprimirLivro
    );
    imprimirItensPorChaveSecao(
        secaoArtigos, autor, compararAutorArtigo, imprimirArtigo
    );
    free(autor);
}

static void ListarAno(Secao *secaoLivros, Secao *secaoArtigos) {
    int ano;
    scanf("%d", &ano);
    getchar();
    puts("- - - LISTA DE TODOS OS ITENS DE UM ANO - - -");
    printf("- Ano: %d\n", ano);
    imprimirItensPorChaveSecao(
        secaoLivros, &ano, compararAnoLivro, imprimirLivro
    );
    imprimirItensPorChaveSecao(
        secaoArtigos, &ano, compararAnoArtigo, imprimirArtigo
    );
}
