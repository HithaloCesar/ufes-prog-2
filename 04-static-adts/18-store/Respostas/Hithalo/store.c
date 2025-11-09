#include "store.h"
#include <stdio.h>

tStore abreLoja() {
    tStore s;
    s.nmProdutos = 0;
    s.nmVendas = 0;
    s.faturamento = 0;

    return s;
}

tStore adicionaProduto(tStore loja, tProduct produto) {
    loja.produtos[loja.nmProdutos++] = produto;

    return loja;
}

int buscaProduto(tStore loja, int id) {
    for (int i = 0; i < loja.nmProdutos; i++) {
        if (obtemId(loja.produtos[i]) == id) {
            return i;
        }
    }

    return -1;
}

tStore aumentaEstoqueLoja(tStore loja, int id, int qtd) {
    int indice = buscaProduto(loja, id);
    loja.produtos[indice] = aumentaEstoqueProduto(loja.produtos[indice], qtd);

    return loja;
}

tStore vendeProdutoLoja(tStore loja, int id, int qtd) {
    int indice = buscaProduto(loja, id);
    loja.produtos[indice] = vendeProduto(loja.produtos[indice], qtd);

    loja.nmVendas += qtd;
    loja.faturamento += obtemPrecoComDesconto(loja.produtos[indice]) * qtd;

    return loja;
}

tStore atualizaDescontoLoja(tStore loja, int id, float desconto) {
    int indice = buscaProduto(loja, id);
    loja.produtos[indice] = atualizaDesconto(loja.produtos[indice], desconto);

    return loja;
}

void imprimeProdutosLoja(tStore loja) {
    for (int i = 0; i < loja.nmProdutos; i++) {
        imprimeProduto(loja.produtos[i]);
    }
}

void imprimeRelatorio(tStore loja) {


    printf("RELATORIO DE VENDAS ATUALIZADO:\n");
    printf("TOTAL DE VENDAS: %d\n", loja.nmVendas);
    printf("FATURAMENTO: %.2f\n", loja.faturamento);
    printf("PRODUTOS EM ESTOQUE: %d\n", obtemEstoqueLoja(loja));
    printf("PRODUTO MAIS VENDIDO:\n");
    imprimeMaisVendido(loja);
}

int obtemEstoqueLoja(tStore loja) {
    int estoqueTotal = 0;
    for (int i = 0; i < loja.nmProdutos; i++) {
        estoqueTotal += obtemEstoque(loja.produtos[i]);
    }

    return estoqueTotal;
}

void imprimeMaisVendido(tStore loja) {
    int indiceMaisVendido = 0;
    for (int i = 0; i < loja.nmProdutos; i++) {
        int vendasProduto = obtemVendas(loja.produtos[i]);
        if (vendasProduto > obtemVendas(loja.produtos[indiceMaisVendido])) {
            indiceMaisVendido = i;
        }
    }

    imprimeProduto(loja.produtos[indiceMaisVendido]);
}
