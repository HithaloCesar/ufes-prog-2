#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 100
#define TAM_MAX_NASCIMENTO 11
#define TAM_MAX_CURSO 50

struct Aluno {
    char nome[TAM_MAX_NOME];
    char dataNascimento[TAM_MAX_NASCIMENTO];
    char curso[TAM_MAX_CURSO];
    int periodo;
    float coeficienteRendimento;
};

tAluno *CriarAluno(
    char *nome,
    char *dataNascimento,
    char *curso,
    int periodo,
    float coeficienteRendimento
) {
    tAluno *aluno = calloc(1, sizeof(*aluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->curso, curso);
    aluno->periodo = periodo;
    aluno->coeficienteRendimento = coeficienteRendimento;

    return aluno;
}

void DestruirAluno(tAluno *aluno) {
    free(aluno);
}

tAluno *LeAluno(FILE *arquivo_binario) {
    char nome[TAM_MAX_NOME];
    char dataNascimento[TAM_MAX_NASCIMENTO];
    char curso[TAM_MAX_CURSO];
    int periodo;
    float coeficienteRendimento;

    fread(nome, sizeof(*nome), TAM_MAX_NOME, arquivo_binario);
    fread(
        dataNascimento,
        sizeof(*dataNascimento),
        TAM_MAX_NASCIMENTO,
        arquivo_binario
    );
    fread(curso, sizeof(*curso), TAM_MAX_CURSO, arquivo_binario);
    fread(&periodo, sizeof(periodo), 1, arquivo_binario);
    fread(
        &coeficienteRendimento,
        sizeof(coeficienteRendimento),
        1,
        arquivo_binario
    );

    tAluno *aluno = CriarAluno(
        nome,
        dataNascimento,
        curso,
        periodo,
        coeficienteRendimento
    );

    return aluno;
}

float GetCoeficienteRendimentoAluno(tAluno *aluno) {
    return aluno->coeficienteRendimento;
}
