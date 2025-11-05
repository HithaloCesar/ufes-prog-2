#include "tDepartamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int qsort_dept(const void *a, const void *b);

tDepartamento CriaDepartamento(
    char *curso1,
    char *curso2,
    char *curso3,
    char *nome,
    int m1,
    int m2,
    int m3,
    char *diretor
) {
    tDepartamento dept;
    strcpy(dept.curso1, curso1);
    strcpy(dept.curso2, curso2);
    strcpy(dept.curso3, curso3);
    strcpy(dept.nome, nome);
    dept.m1 = m1;
    dept.m2 = m2;
    dept.m3 = m3;
    strcpy(dept.diretor, diretor);

    return dept;
}

void ImprimeAtributosDepartamento(tDepartamento depto) {
    putchar('\n');

    printf("Departamento: %s\n", depto.nome);
    printf("\tDiretor: %s\n", depto.diretor);

    printf("\t1o curso: %s\n", depto.curso1);
    printf("\tMedia do 1o curso: %d\n", depto.m1);

    printf("\t2o curso: %s\n", depto.curso2);
    printf("\tMedia do 2o curso: %d\n", depto.m2);

    printf("\t3o curso: %s\n", depto.curso3);
    printf("\tMedia do 3o curso: %d\n", depto.m3);

    float mediaCursos = (depto.m1 + depto.m2 + depto.m3) / 3.0;
    printf("\tMedia dos cursos: %.2f\n", mediaCursos);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos) {
    qsort(vetor_deptos, num_deptos, sizeof(tDepartamento), qsort_dept);
}

static int qsort_dept(const void *a, const void *b) {
    tDepartamento *d1 = (tDepartamento*)a;
    tDepartamento *d2 = (tDepartamento*)b;

    float mediaCursosD1 = (d1->m1 + d1->m2 + d1->m3) / 3.0;
    float mediaCursosD2 = (d2->m1 + d2->m2 + d2->m3) / 3.0;

    return mediaCursosD2 - mediaCursosD1;
}
