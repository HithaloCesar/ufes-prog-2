#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

enum genero {
    GENERO_M = 'M',
    GENERO_F = 'F',
    GENERO_O = 'O'
};

struct Aluno {
    char *nome;
    enum genero genero;
    float nota;
};

tAluno *CriaAluno(void) {
    tAluno *aluno = calloc(1, sizeof(*aluno));

    return aluno;
}

void DestroiAluno(data_type aluno) {
    tAluno *a = (tAluno*)aluno;
    free(a->nome);
    free(a);
}

void LeAluno(tAluno *aluno) {
    scanf(" %m[^;];%c;%f", &aluno->nome, &aluno->genero, &aluno->nota);
    getchar();
}

char GetGeneroAluno(tAluno *aluno) {
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno) {
    return aluno->nota;
}
