#include "alimento.h"
#include <stdio.h>
#include <string.h>

tAlimento criaAlimento(char *nome, float preco, float qtd) {
    tAlimento alimento;
    strcpy(alimento.nome, nome);
    alimento.preco = preco;
    alimento.quantidade = qtd;
    alimento.qtdConsumida = 0;

    return alimento;
}

tAlimento leAlimento() {
    char nome[32];
    float preco;
    float quantidade;

    scanf(" %[^\n] %f %f", nome, &preco, &quantidade);

    return criaAlimento(nome, preco, quantidade);
}

tAlimento consumirAlimento(tAlimento alimento, float qtd) {
    alimento.qtdConsumida += qtd;
    alimento.quantidade -= qtd;

    return alimento;
}

float rendaAlimento(tAlimento alimento) {
    return alimento.preco * alimento.qtdConsumida / 1000;
}

void imprimeAlimento(tAlimento alimento) {
    printf("--------------------\n");
    printf("Nome: %s\n", alimento.nome);
    printf("Quantidade: %.2f\n", alimento.quantidade);
    printf("Preco: R$ %.2f\n", alimento.preco);
    printf("Quantidade consumida: %.2f\n", alimento.qtdConsumida);
    printf("Renda: R$ %.2f\n", rendaAlimento(alimento));
    printf("--------------------\n");
}
