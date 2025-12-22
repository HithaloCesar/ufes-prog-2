#include "funcionario.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

tFuncionario *CriaFuncionario(void) {
    tFuncionario *f = malloc(sizeof(*f));

    return f;
}

void ApagaFuncionario(tFuncionario *f) {
    free(f);
}

void LeFuncionario(tFuncionario *f) {
    scanf("%d %f", &f->id, &f->salario);
    getchar();
}

int GetIdFuncionario(tFuncionario *f) {
    return f->id;
}

void ImprimeFuncionario(tFuncionario *f) {
    printf("- Funcionario %d: RS %.2f\n", f->id, f->salario);
}
