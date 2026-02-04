#include <stdlib.h>
#include <stdio.h>

#include "aluno.h"

#define FILENAME "alunos.bin"

int main(void) {
    fputs("Digite o numero de alunos: ", stdout);
    int numeroAlunos;
    scanf("%d", &numeroAlunos);
    getchar();

    Aluno **alunos = CriaVetorAlunos(numeroAlunos);
    LeAlunos(alunos, numeroAlunos);
    SalvaAlunosBinario(alunos, FILENAME, numeroAlunos);
    LiberaAlunos(alunos, numeroAlunos);

    alunos = CriaVetorAlunos(numeroAlunos);
    CarregaAlunosBinario(alunos, FILENAME);
    ImprimeAlunos(alunos, numeroAlunos);
    LiberaAlunos(alunos, numeroAlunos);

    return EXIT_SUCCESS;
}
