#include "banco.h"
#include <stdlib.h>
#include <stdio.h>

struct Banco {
    char *nome;
    Vector *agencias;
};

tBanco *CriaBanco(void) {
    tBanco *banco = calloc(1, sizeof(*banco));

    banco->agencias = VectorConstruct();

    return banco;
}

void DestroiBanco(tBanco *banco) {
    free(banco->nome);
    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco);
}

void LeBanco(tBanco *banco) {
    scanf(" %m[^\n]", &banco->nome);
    getchar();
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia) {
    VectorPushBack(banco->agencias, agencia);
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente) {
    int qtdAgencias = VectorSize(banco->agencias);
    for (int i = 0; i < qtdAgencias; i++) {
        tAgencia *agencia = VectorGet(banco->agencias, i);
        if (ComparaAgencia(numAgencia, agencia)) {
            AdicionaConta(agencia, cliente);
            return;
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco) {
    printf("%s\n", banco->nome);

    puts("Lista de agencias:");

    int qtdAgencias = VectorSize(banco->agencias);
    for (int i = 0; i < qtdAgencias; i++) {
        tAgencia *agencia = VectorGet(banco->agencias, i);
        ImprimeDadosAgencia(agencia);
    }
}
