#include <stdlib.h>
#include <stdio.h>
#include "departamento.h"

static int LeDepartamento(tDepartamento *d) {
    char nome[STRING_MAX], diretor[STRING_MAX];
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    int m1, m2, m3;

    scanf(" %[^\n]", nome);
    scanf(" %[^\n]", diretor);
    scanf(" %[^\n]", c1);
    scanf(" %[^\n]", c2);
    scanf(" %[^\n]", c3);
    scanf("%d %d %d", &m1, &m2, &m3);
    getchar();

    if (!ValidaMediaDepartamento(m1) ||
        !ValidaMediaDepartamento(m2) ||
        !ValidaMediaDepartamento(m3)
    ) {
        return 0;
    }

    PreencheDadosDepartamento(d, c1, c2, c3, nome, m1, m2, m3, diretor);

    return 1;
}

int main(int argc, char *argv[]) {
    int numDepartamentos;
    scanf("%d", &numDepartamentos);
    getchar();

    tDepartamento **deptos = malloc(numDepartamentos * sizeof(*deptos));

    for (int i = 0; i < numDepartamentos; i++) {
        deptos[i] = CriaDepartamento();
        if (!LeDepartamento(deptos[i])) {
            for (int j = 0; j <= i; j++) {
                LiberaMemoriaDepartamento(deptos[j]);
            }
            free(deptos);
            return EXIT_FAILURE;
        }
    }

    OrdenaPorMediaDepartamentos(deptos, numDepartamentos);

    for (int i = 0; i < numDepartamentos; i++) {
        ImprimeAtributosDepartamento(deptos[i]);
    }

    for (int i = 0; i < numDepartamentos; i++) {
        LiberaMemoriaDepartamento(deptos[i]);
    }
    free(deptos);

    return EXIT_SUCCESS;
}
