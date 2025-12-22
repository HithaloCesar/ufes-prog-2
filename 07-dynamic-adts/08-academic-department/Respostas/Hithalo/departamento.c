#include "departamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM_CURSOS 3

static int QsortDepartamento(const void *a, const void *b);

tDepartamento *CriaDepartamento(void) {
    tDepartamento *d = calloc(1, sizeof(*d));

    d->c1 = calloc(STRING_MAX, sizeof(*d->c1));
    d->c2 = calloc(STRING_MAX, sizeof(*d->c2));
    d->c3 = calloc(STRING_MAX, sizeof(*d->c3));
    d->nome = calloc(STRING_MAX, sizeof(*d->nome));
    d->diretor = calloc(STRING_MAX, sizeof(*d->diretor));

    return d;
}

void PreencheDadosDepartamento(
    tDepartamento *d,
    char *c1,
    char *c2,
    char *c3,
    char *nome,
    int m1,
    int m2,
    int m3,
    char *diretor
) {
    strcpy(d->c1, c1);
    strcpy(d->c2, c2);
    strcpy(d->c3, c3);
    strcpy(d->nome, nome);
    strcpy(d->diretor, diretor);

    d->m1 = m1;
    d->m2 = m2;
    d->m3 = m3;
}

void LiberaMemoriaDepartamento(tDepartamento *d) {
    free(d->c1);
    free(d->c2);
    free(d->c3);
    free(d->nome);
    free(d->diretor);

    free(d);
}

void ImprimeAtributosDepartamento(tDepartamento *d) {
    double media = CalculaMediaGeralDepartamento(d);
    double desvioPadrao = CalculaDesvioPadraoDepartamento(d);

    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", d->nome);
    printf("diretor => %s\n", d->diretor);
    printf("curso1 => %s, media1 => %d\n", d->c1, d->m1);
    printf("curso2 => %s, media2 => %d\n", d->c2, d->m2);
    printf("curso3 => %s, media3 => %d\n", d->c3, d->m3);
    printf("media geral => %.2f\n", media);
    printf("desvio padrao => %.2f\n", desvioPadrao);
    putchar('\n');
}

int ValidaMediaDepartamento(int media) {
    return media >= 0 && media <= 10;
}

double CalculaDesvioPadraoDepartamento(tDepartamento *d) {
    double media = CalculaMediaGeralDepartamento(d);
    double x1 = pow((d->m1 - media), 2);
    double x2 = pow((d->m2 - media), 2);
    double x3 = pow((d->m3 - media), 2);
    double variancia = (x1 + x2 + x3) / NUM_CURSOS;

    return sqrt(variancia);
}

double CalculaMediaGeralDepartamento(tDepartamento *d) {
    return (double)(d->m1 + d->m2 + d->m3) / NUM_CURSOS;
}

void OrdenaPorMediaDepartamentos(tDepartamento *d[], int tamanho) {
    qsort(d, tamanho, sizeof(*d), QsortDepartamento);
}

static int QsortDepartamento(const void *a, const void *b) {
    tDepartamento *d1 = *((tDepartamento**)a);
    tDepartamento *d2 = *((tDepartamento**)b);

    double mediaD1 = CalculaMediaGeralDepartamento(d1);
    double mediaD2 = CalculaMediaGeralDepartamento(d2);

    if (mediaD2 != mediaD1) {
        return (mediaD2 - mediaD1 > 0) ? 1 : -1;
    }

    return 0;
}
