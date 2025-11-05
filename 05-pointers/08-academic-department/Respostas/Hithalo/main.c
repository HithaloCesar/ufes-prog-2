#include <stdlib.h>
#include <stdio.h>
#include "tDepartamento.h"

#define MAX_DEPTOS 16

int main(void) {
    int numDepartamentos;
    scanf("%d", &numDepartamentos);

    tDepartamento deptos[MAX_DEPTOS];
    int deptoCount = 0;

    int i = 0;
    while (i < numDepartamentos) {
        char nome[STRING_MAX];
        char diretor[STRING_MAX];
        char curso1[STRING_MAX];
        char curso2[STRING_MAX];
        char curso3[STRING_MAX];
        int m1, m2, m3;

        scanf(" %[^\n]", nome);
        scanf(" %[^\n]", diretor);
        scanf(" %[^\n]", curso1);
        scanf(" %[^\n]", curso2);
        scanf(" %[^\n]", curso3);
        scanf("%d %d %d", &m1, &m2, &m3);

        if (m1 < 0 || m2 < 0 || m3 < 0 || m1 > 10 || m2 > 10 || m3 > 10) {
            printf("Digite um departamento com médias válidas\n");
            continue;
        }

        tDepartamento dept = CriaDepartamento(
            curso1, curso2, curso3, nome, m1, m2, m3, diretor
        );

        deptos[deptoCount++] = dept;

        i++;
    }

    OrdenaDepartamentosPorMedia(deptos, numDepartamentos);

    for (int i = 0; i < numDepartamentos; i++) {
        ImprimeAtributosDepartamento(deptos[i]);
    }

    return EXIT_SUCCESS;
}
