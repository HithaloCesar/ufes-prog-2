#include "aluno.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno {
    char *nome;
    char *dtNasc;
    char *cursoUfes;
    char *periodoIngresso;
    int percConclusao;
    float CRA;
};

static int SalvaDadoBinario(void *n, int tamDado, FILE *file);
static int SalvaStringBinario(char *str, FILE *file);
static int CarregaDadoBinario(void *dado, int tamDado, FILE *file);
static int CarregaStringBinario(char **str, FILE *file);

Aluno **CriaVetorAlunos(int numeroAlunos) {
    Aluno **alunos = calloc(numeroAlunos, sizeof(*alunos));

    return alunos;
}

Aluno *CriaAluno(
    char *nome,
    char *dtNasc,
    char *cursoUfes,
    char *periodoIngresso,
    int percConclusao,
    float CRA
) {
    Aluno *aluno = calloc(1, sizeof(*aluno));

    aluno->nome = nome;
    aluno->dtNasc = dtNasc;
    aluno->cursoUfes = cursoUfes;
    aluno->periodoIngresso = periodoIngresso;
    aluno->percConclusao = percConclusao;
    aluno->CRA = CRA;

    return aluno;
}

void LeAlunos(Aluno **vetorAlunos, int numeroAlunos) {
    for (int i = 0; i < numeroAlunos; i++) {
        char *nome;
        char *dtNasc;
        char *cursoUfes;
        char *periodoIngresso;
        int percConclusao;
        float CRA;

        scanf(" %m[^\n]", &nome);
        scanf(" %m[^\n]", &dtNasc);
        scanf(" %m[^\n]", &cursoUfes);
        scanf(" %m[^\n]", &periodoIngresso);
        scanf("%d", &percConclusao);
        scanf("%f", &CRA);
        getchar();

        vetorAlunos[i] = CriaAluno(
            nome,
            dtNasc,
            cursoUfes,
            periodoIngresso,
            percConclusao,
            CRA
        );
    }
}

void LiberaAlunos(Aluno **alunos, int numeroAlunos) {
    for (int i = 0; i < numeroAlunos; i++) {
        free(alunos[i]->nome);
        free(alunos[i]->dtNasc);
        free(alunos[i]->cursoUfes);
        free(alunos[i]->periodoIngresso);
        free(alunos[i]);
    }

    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
    FILE *alunosBin = fopen(fileName, "wb");

    int numBytesSalvos = 0;

    numBytesSalvos += SalvaDadoBinario(
        &numeroAlunos,
        sizeof(numeroAlunos),
        alunosBin
    );

    for (int i = 0; i < numeroAlunos; i++) {
        numBytesSalvos += SalvaStringBinario(alunos[i]->nome, alunosBin);
        numBytesSalvos += SalvaStringBinario(alunos[i]->dtNasc, alunosBin);
        numBytesSalvos += SalvaStringBinario(alunos[i]->cursoUfes, alunosBin);
        numBytesSalvos += SalvaStringBinario(
            alunos[i]->periodoIngresso,
            alunosBin
        );

        numBytesSalvos += SalvaDadoBinario(
            &alunos[i]->percConclusao,
            sizeof(alunos[i]->percConclusao),
            alunosBin
        );

        numBytesSalvos += SalvaDadoBinario(
            &alunos[i]->CRA,
            sizeof(alunos[i]->CRA),
            alunosBin
        );
    }

    fclose(alunosBin);

    printf("Numero de bytes salvos: %d\n", numBytesSalvos);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
    FILE *alunosBin = fopen(fileName, "rb");

    int numeroAlunos;
    fread(&numeroAlunos, sizeof(numeroAlunos), 1, alunosBin);

    for (int i = 0; i < numeroAlunos; i++) {
        alunos[i] = calloc(1, sizeof(*alunos[i]));

        CarregaStringBinario(&alunos[i]->nome, alunosBin);
        CarregaStringBinario(&alunos[i]->dtNasc, alunosBin);
        CarregaStringBinario(&alunos[i]->cursoUfes, alunosBin);
        CarregaStringBinario(&alunos[i]->periodoIngresso, alunosBin);
        CarregaDadoBinario(
            &alunos[i]->percConclusao,
            sizeof(alunos[i]->percConclusao),
            alunosBin
        );
        CarregaDadoBinario(
            &alunos[i]->CRA,
            sizeof(alunos[i]->CRA),
            alunosBin
        );
    }

    fclose(alunosBin);
}

void ImprimeAlunos(Aluno **alunos, int numeroAlunos) {
    for (int i = 0; i < numeroAlunos; i++) {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dtNasc);
        printf("Curso: %s\n", alunos[i]->cursoUfes);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->percConclusao);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}

static int SalvaDadoBinario(void *dado, int tamDado, FILE *file) {
    return fwrite(dado, tamDado, 1, file) * tamDado;
}

static int SalvaStringBinario(char *str, FILE *file) {
    int numBytesSalvos = 0;

    int tamNome = strlen(str);
    numBytesSalvos += SalvaDadoBinario(&tamNome, sizeof(tamNome), file);
    numBytesSalvos += SalvaDadoBinario(str, tamNome, file);

    return numBytesSalvos;
}

static int CarregaDadoBinario(void *dado, int tamDado, FILE *file) {
    return fread(dado, tamDado, 1, file) * tamDado;
}

static int CarregaStringBinario(char **str, FILE *file) {
    int numBytesCarregados = 0;

    int tamNome = 0;
    numBytesCarregados += CarregaDadoBinario(&tamNome, sizeof(tamNome), file);

    *str = malloc(tamNome + 1);

    numBytesCarregados += CarregaDadoBinario(*str, tamNome, file);

    (*str)[tamNome] = '\0';

    return numBytesCarregados;
}
