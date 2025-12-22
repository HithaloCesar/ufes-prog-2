#include "loja.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_VENDEDORES 10

struct Loja {
    int id;
    int totalVendedores;
    int maxVendedores;
    float aluguel;
    float lucro;
    tVendedor** vendedores;
};

tLoja *AbreLoja(int id, float aluguel) {
    tLoja *loja = calloc(1, sizeof(*loja));

    loja->vendedores = calloc(MAX_VENDEDORES, sizeof(*loja->vendedores));

    loja->id = id;
    loja->aluguel = aluguel;

    return loja;
}

void ApagaLoja(tLoja *loja) {
    for (int i = 0; i < loja->totalVendedores; i++) {
        ApagaVendedor(loja->vendedores[i]);
    }

    free(loja->vendedores);
    free(loja);
}

int VerificaIdLoja(tLoja *loja, int id) {
    return loja->id == id;
}

void ContrataVendedor(tLoja *loja, tVendedor* vendedor) {
    loja->vendedores[loja->totalVendedores++] = vendedor;
}

void RegistraVenda(tLoja *loja, char *nome, float valor) {
    for (int i = 0; i < loja->totalVendedores; i++) {
        if (VerificaNomeVendedor(loja->vendedores[i], nome)) {
            ContabilizaVenda(loja->vendedores[i], valor);
            return;
        }
    }
}

void CalculaLucro(tLoja *loja) {
    for (int i = 0; i < loja->totalVendedores; i++) {
        loja->lucro += GetTotalVendido(loja->vendedores[i]) - GetTotalRecebido(loja->vendedores[i]);
    }
    loja->lucro -= loja->aluguel;
}

void ImprimeRelatorioLoja(tLoja *loja) {
    printf("Loja %d: Lucro total: R$ %.2f\n", loja->id, loja->lucro);
    for (int i = 0; i < loja->totalVendedores; i++) {
        ImprimeRelatorioVendedor(loja->vendedores[i]);
    }
}
