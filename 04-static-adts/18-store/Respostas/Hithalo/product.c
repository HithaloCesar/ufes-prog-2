#include "product.h"
#include <stdio.h>
#include <string.h>

tProduct leProduto(void) {
    char nome[MAX_NOME];
    float desconto, preco;
    int estoque, id;

    printf("Nome do Produto: ");
    scanf(" %[^\n]\n", nome);

    printf("ID: ");
    scanf("%d\n", &id);

    printf("Preco: ");
    scanf("%f\n", &preco);

    printf("Desconto: ");
    scanf("%f\n", &desconto);

    printf("Estoque: ");
    scanf("%d\n", &estoque);

    return criaProduto(nome, desconto, preco, estoque, id);
}

tProduct criaProduto(
    char *nome,
    float desconto,
    float preco,
    int estoque,
    int id
) {
    tProduct p;

    strcpy(p.nome, nome);
    p.id = id;
    p.preco = preco;
    p.desconto = desconto;
    p.estoque = estoque;
    p.vendas = 0;

    return p;
}

float obtemDesconto(tProduct produto) {
    return produto.desconto;
}

float obtempreco(tProduct produto) {
    return produto.preco;
}

float obtemPrecoComDesconto(tProduct produto) {
    return (1.0 - produto.desconto) * produto.preco;
}

int obtemEstoque(tProduct produto) {
    return produto.estoque;
}

int obtemVendas(tProduct produto) {
    return produto.vendas;
}

int obtemId(tProduct produto) {
    return produto.id;
}

tProduct aumentaEstoqueProduto(tProduct produto, int qtd) {
    if (qtd > 0) {
        produto.estoque += qtd;
    } else {
        printf("Quantidade inválida.\n");
    }

    return produto;
}

tProduct vendeProduto(tProduct produto, int qtd) {
    if (qtd > 0 && produto.estoque >= qtd) {
        produto.estoque -= qtd;
        produto.vendas += qtd;
    } else {
        printf("Quantidade inválida.\n");
    }

    return produto;
}

tProduct atualizaDesconto(tProduct produto, float desconto) {
    if (desconto >= 0 && desconto <= 1) {
        produto.desconto = desconto;
    } else {
        printf("Quantidade inválida.\n");
    }

    return produto;
}

bool ehMesmoId(tProduct produto, int id) {
    return produto.id == id;
}

void imprimeProduto(tProduct produto) {
    printf(
        "Produto: %s, Preco atual: %.2f, Qtd no estoque: %d, Qtd vendida: %d\n",
        produto.nome,
        obtemPrecoComDesconto(produto),
        produto.estoque,
        produto.vendas
    );
}
