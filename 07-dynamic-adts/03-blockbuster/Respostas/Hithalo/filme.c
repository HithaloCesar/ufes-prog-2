#include "filme.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tFilme *CriarFilme(void) {
    tFilme *filme = calloc(1, sizeof(*filme));

    return filme;
}

void LeFilme(tFilme *filme, int codigo) {
    scanf(
        "%[^,], %d, %d",
        filme->nome, &filme->valor, &filme->qtdEstoque
    );
    getchar();

    filme->codigo = codigo;
}

void DestruirFilme(tFilme *filme) {
    free(filme);
}

int ObterCodigoFilme(tFilme *filme) {
    return filme->codigo;
}

void ImprimirNomeFilme(tFilme *filme) {
    printf("%s", filme->nome);
}

int ObterValorFilme(tFilme *filme) {
    return filme->valor;
}

int ObterQtdEstoqueFilme(tFilme *filme) {
    return filme->qtdEstoque;
}

int ObterQtdAlugadaFilme(tFilme *filme) {
    return filme->qtdAlugada;
}

int EhMesmoCodigoFilme(tFilme *filme, int codigo) {
    return filme->codigo == codigo;
}

void AlugarFilme(tFilme *filme) {
    filme->qtdEstoque--;
    filme->qtdAlugada++;
}

void DevolverFilme(tFilme *filme) {
    filme->qtdAlugada--;
    filme->qtdEstoque++;
}

int CompararNomesFilmes(tFilme *filme1, tFilme *filme2) {
    return strcmp(filme1->nome, filme2->nome);
}
