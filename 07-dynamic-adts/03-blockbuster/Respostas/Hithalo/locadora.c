#include "locadora.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_FILMES 100
#define TAM_CODIGOS_INICIAL 16

static int LerCodigos(tLocadora *locadora, int **codigos);

static tFilme *BuscaFilmePorCodigo(tLocadora *locadora, int codigo);

static int comparaFilme(const void *a, const void *b);

tLocadora *CriarLocadora(void) {
    tLocadora *locadora = calloc(1, sizeof(*locadora));

    return locadora;
}

void DestruirLocadora(tLocadora *locadora) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora->filme);

    free(locadora);
}

int VerificarFilmeCadastrado(tLocadora *locadora, int codigo) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        if (EhMesmoCodigoFilme(locadora->filme[i], codigo)) {
            return 1;
        }
    }

    return 0;
}

void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme) {
    if (!locadora->filme) {
        locadora->filme = malloc(MAX_FILMES * sizeof(*locadora->filme));
    }

    int codigoFilme = ObterCodigoFilme(filme);
    for (int i = 0; i < locadora->numFilmes; i++) {
        if (EhMesmoCodigoFilme(locadora->filme[i], codigoFilme)) {
            printf("Filme ja cadastrado no estoque\n");
            DestruirFilme(filme);
            return;
        }
    }

    locadora->filme[locadora->numFilmes++] = filme;
    printf("Filme cadastrado %d - ", codigoFilme);
    ImprimirNomeFilme(filme);
    putchar('\n');
}

void LerCadastroLocadora(tLocadora *Locadora) {
    bool continuarOperacao = true;
    while (continuarOperacao) {
        int codigo;
        char c;
        if (scanf("%d,", &codigo) == 1) {
            tFilme *filme = CriarFilme();
            LeFilme(filme, codigo);
            CadastrarFilmeLocadora(Locadora, filme);
        } else if (scanf(" %c", &c) == 1 && c == '#') {
            getchar();
            continuarOperacao = false;
        }
    }
}

void AlugarFilmesLocadora(
    tLocadora *locadora,
    int *codigos,
    int quantidadeCodigos
) {
    int totalAlugados = 0;
    int custo = 0;
    for (int i = 0; i < quantidadeCodigos; i++) {
        tFilme *filme = BuscaFilmePorCodigo(locadora, codigos[i]);

        if (!filme) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
            continue;
        }

        if (ObterQtdEstoqueFilme(filme) == 0) {
            printf("Filme %d - ", codigos[i]);
            ImprimirNomeFilme(filme);
            printf(" nao disponivel no estoque. Volte mais tarde.\n");
            continue;
        }

        AlugarFilme(filme);
        custo += ObterValorFilme(filme);
        totalAlugados++;
    }

    if (totalAlugados == 0) {
        return;
    }

    printf(
        "Total de filmes alugados: %d com custo de R$%d\n",
        totalAlugados,
        custo
    );
}

void LerAluguelLocadora(tLocadora *locadora) {
    int *codigos;
    int quantidadeCodigos = LerCodigos(locadora, &codigos);

    AlugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
    free(codigos);
}

void DevolverFilmesLocadora(
    tLocadora *locadora,
    int *codigos,
    int quantidadeCodigos
) {
    for (int i = 0; i < quantidadeCodigos; i++) {
        tFilme *filme = BuscaFilmePorCodigo(locadora, codigos[i]);

        if (!filme) {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
            continue;
        }

        if (ObterQtdAlugadaFilme(filme) == 0) {
            printf("Nao e possivel devolver o filme %d - ", codigos[i]);
            ImprimirNomeFilme(filme);
            printf(".\n");
            continue;
        }

        DevolverFilme(filme);
        locadora->lucro += ObterValorFilme(filme);

        printf("Filme %d - ", codigos[i]);
        ImprimirNomeFilme(filme);
        printf(" Devolvido!\n");
    }
}

void LerDevolucaoLocadora(tLocadora *locadora) {
    int *codigos;
    int quantidadeCodigos = LerCodigos(locadora, &codigos);

    DevolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
    free(codigos);
}

void OrdenarFilmesLocadora(tLocadora *locadora) {
    qsort(
        locadora->filme,
        locadora->numFilmes,
        sizeof(*locadora->filme),
        comparaFilme
    );
}

void ConsultarEstoqueLocadora(tLocadora *locadora) {
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora->numFilmes; i++) {
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(
            " Fitas em estoque: %d\n",
            ObterQtdEstoqueFilme(locadora->filme[i])
        );
    }
}

void ConsultarLucroLocadora(tLocadora *locadora) {
    if (locadora->lucro > 0) {
        printf("Lucro total R$%d\n", locadora->lucro);
    }
}

static int LerCodigos(tLocadora *locadora, int **codigos) {
    int quantidadeCodigos = 0;
    int tamanhoCodigos = TAM_CODIGOS_INICIAL;
    *codigos = malloc(tamanhoCodigos * sizeof(*codigos));

    bool continuarLeitura = true;
    while (continuarLeitura) {
        int codigo;
        char c;
        if (scanf("%d", &codigo) == 1) {
            getchar();
            if (quantidadeCodigos == tamanhoCodigos) {
                tamanhoCodigos *= 2;
                *codigos = realloc(
                    *codigos, tamanhoCodigos * sizeof(*codigos)
                );
            }
            (*codigos)[quantidadeCodigos++] = codigo;
        } else if (scanf(" %c", &c) == 1 && c == '#') {
            getchar();
            continuarLeitura = false;
        }
    }

    return quantidadeCodigos;
}

static tFilme *BuscaFilmePorCodigo(tLocadora *locadora, int codigo) {
    for (int i = 0; i < locadora->numFilmes; i++) {
        if (EhMesmoCodigoFilme(locadora->filme[i], codigo)) {
            return locadora->filme[i];
        }
    }

    return NULL;
}

static int comparaFilme(const void *a, const void *b) {
    return CompararNomesFilmes(*(tFilme**)a, *(tFilme**)b);
}
