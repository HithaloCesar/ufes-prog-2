#include <stdlib.h>
#include <stdio.h>
#include "empresa.h"

int main(void) {
    int qtdEmpresas;
    scanf("%d", &qtdEmpresas);
    getchar();

    tEmpresa **empresas = calloc(qtdEmpresas, sizeof(*empresas));

    for (int i = 0; i < qtdEmpresas; i++) {
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);
    }

    for (int i = 0; i < qtdEmpresas; i++) {
        ImprimeEmpresa(empresas[i]);
    }

    for (int i = 0; i < qtdEmpresas; i++) {
        ApagaEmpresa(empresas[i]);
    }
    free(empresas);

    return EXIT_SUCCESS;
}
