#include "vendedor.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

tVendedor *RegistraVendedor(char *nome, float salario, float prct_comissao) {
    tVendedor *v = calloc(1, sizeof(*v));
    v->nome = malloc((strlen(nome) + 1) * sizeof(*v->nome));

    strcpy(v->nome, nome);
    v->salario = salario;
    v->prct_comissao = prct_comissao;

    return v;
}

void ApagaVendedor(tVendedor *vendedor) {
    free(vendedor->nome);
    free(vendedor);
}

int VerificaNomeVendedor(tVendedor *vendedor, char *nome) {
    return !strcmp(vendedor->nome, nome);
}

void ContabilizaVenda(tVendedor *vendedor, float valor) {
    vendedor->valor_vendido += valor;
}

float GetSalario(tVendedor *vendedor) {
    return vendedor->salario;
}

float GetComissao(tVendedor *vendedor) {
    return vendedor->prct_comissao * vendedor->valor_vendido;
}

float GetTotalVendido(tVendedor *vendedor) {
    return vendedor->valor_vendido;
}

float GetTotalRecebido(tVendedor *vendedor) {
    return GetSalario(vendedor) + GetComissao(vendedor);
}

void ImprimeRelatorioVendedor(tVendedor *vendedor) {
    float totalVendido = GetTotalVendido(vendedor);
    float totalRecebido = GetTotalRecebido(vendedor);
    printf("\t%s > Total vendido: R$%.2f\n", vendedor->nome, totalVendido);
    printf("\t\tTotal recebido: R$%.2f\n", totalRecebido);
}
