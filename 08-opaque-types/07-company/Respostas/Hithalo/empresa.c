#include "empresa.h"
#include <stdlib.h>
#include <stdio.h>

struct empresa {
    int id;
    tFuncionario **funcionarios;
    int qtdFuncionarios;
};

tEmpresa *CriaEmpresa(void) {
    tEmpresa *e = calloc(1, sizeof(*e));

    return e;
}

void LeEmpresa(tEmpresa *e) {
    int qtdFuncionarios;
    scanf("%d %d", &e->id, &qtdFuncionarios);
    getchar();

    e->funcionarios = calloc(qtdFuncionarios, sizeof(*e->funcionarios));

    for (int i = 0; i < qtdFuncionarios; i++) {
        tFuncionario *f = CriaFuncionario();
        LeFuncionario(f);
        ContrataFuncionarioEmpresa(e, f);
    }
}

void ApagaEmpresa(tEmpresa *e) {
    for (int i = 0; i < e->qtdFuncionarios; i++) {
        ApagaFuncionario(e->funcionarios[i]);
    }
    free(e->funcionarios);
    free(e);
}

void ContrataFuncionarioEmpresa(tEmpresa *e, tFuncionario *f) {
    int idF = GetIdFuncionario(f);
    for (int i = 0; i < e->qtdFuncionarios; i++) {
        if (GetIdFuncionario(e->funcionarios[i]) == idF) {
            printf(
                "A empresa %d ja possui um funcionario com o id %d\n",
                e->id, idF
            );
            ApagaFuncionario(f);
            return;
        }
    }

    e->funcionarios[e->qtdFuncionarios++] = f;
}

void ImprimeEmpresa(tEmpresa *e) {
    printf("Empresa %d:\n", e->id);
    for (int i = 0; i < e->qtdFuncionarios; i++) {
        ImprimeFuncionario(e->funcionarios[i]);
    }
    putchar('\n');
}
