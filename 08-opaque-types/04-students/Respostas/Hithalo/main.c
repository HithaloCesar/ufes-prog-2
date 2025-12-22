#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

static int ComparaAluno(const void *a, const void *b) {
    return ComparaMatricula(*(tAluno**)a, *(tAluno**)b);
}

int main(void) {
    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    getchar();

    tAluno **alunos = malloc(qtdAlunos * sizeof(*alunos));

    for (int i = 0; i < qtdAlunos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    qsort(alunos, qtdAlunos, sizeof(*alunos), ComparaAluno);

    for (int i = 0; i < qtdAlunos; i++) {
        if (VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
    }

    for (int i = 0; i < qtdAlunos; i++) {
        ApagaAluno(alunos[i]);
    }
    free(alunos);

    return EXIT_SUCCESS;
}
