#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

#define MEDIA_PARA_APROVACAO 7

tAluno *CriaAluno(void) {
    tAluno *aluno = calloc(1, sizeof(*aluno));

    return aluno;
}

void ApagaAluno(tAluno *aluno) {
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno) {
    scanf(" %m[^\n]", &aluno->nome);
    scanf("%d", &aluno->matricula);
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
    getchar();
}

int ComparaMatricula(tAluno *aluno1, tAluno *aluno2) {
    if (aluno1->matricula != aluno2->matricula) {
        return (aluno1->matricula - aluno2->matricula < 0) ? -1 : 1;
    }

    return 0;
}

int CalculaMediaAluno(tAluno *aluno) {
    return (aluno->n1 + aluno->n2 + aluno->n3) / 3;
}

int VerificaAprovacao(tAluno *aluno) {
    return CalculaMediaAluno(aluno) >= MEDIA_PARA_APROVACAO;
}

void ImprimeAluno(tAluno *aluno) {
    printf("%s\n", aluno->nome);
}
