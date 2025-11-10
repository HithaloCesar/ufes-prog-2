#include "restaurante.h"
#include <stdio.h>
#include <string.h>

tRestaurante criaRestaurante(char *nome) {
    tRestaurante restaurante;
    strcpy(restaurante.nome, nome);
    restaurante.numeroAlimentos = 0;

    return restaurante;
}

tRestaurante leRestaurante() {
    char nome[32];
    scanf("%[^\n]", nome);

    return criaRestaurante(nome);
}

tRestaurante cadastraAlimento(tRestaurante r, tAlimento a) {
    r.alimentos[r.numeroAlimentos++] = a;

    return r;
}

tRestaurante consumirAlimentoRestaurante(tRestaurante r,
                                         char *nome, float qtd) {
    for (int i = 0; i < r.numeroAlimentos; i++) {
        if (strcmp(r.alimentos[i].nome, nome) == 0) {
            r.alimentos[i] = consumirAlimento(r.alimentos[i], qtd);
            break;
        }
    }

    return r;
}

float quantidadeConsumida(tRestaurante r) {
    float qtd_consumida = 0;
    for (int i = 0; i < r.numeroAlimentos; i++) {
        qtd_consumida += r.alimentos[i].qtdConsumida;
    }

    return qtd_consumida;
}

float rendaTotal(tRestaurante r) {
    float renda_total = 0;
    for (int i = 0; i < r.numeroAlimentos; i++) {
        renda_total += rendaAlimento(r.alimentos[i]);
    }

    return renda_total;
}

void imprimeRestaurante(tRestaurante r) {
    printf("Nome: %s\n", r.nome);
    printf("Alimentos:\n");

    for (int i = 0; i < r.numeroAlimentos; i++) {
        imprimeAlimento(r.alimentos[i]);
    }

    printf("Quantidade total consumida: %.2f\n", quantidadeConsumida(r));
    printf("Renda total: R$ %.2f\n", rendaTotal(r));
}
