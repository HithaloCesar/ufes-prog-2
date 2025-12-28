#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>

#define NOTA_MINIMA_PARA_APROVACAO 6

enum genero {
    GENERO_M = 'M',
    GENERO_F = 'F',
    GENERO_O = 'O'
};

void ImprimeRelatorio(Vector *alunos) {
    float somaNotas = 0;
    int numAprovados = 0;
    int numGeneroM = 0;
    int numGeneroF = 0;
    int numGeneroO = 0;

    int numAlunos = VectorSize(alunos);
    for (int i = 0; i < numAlunos; i++) {
        tAluno *a = (tAluno *)VectorGet(alunos, i);

        float nota = GetNotaAluno(a);
        somaNotas += nota;
        if (nota >= NOTA_MINIMA_PARA_APROVACAO) {
            numAprovados++;
        }

        char genero = GetGeneroAluno(a);
        if (genero == GENERO_M) {
            numGeneroM++;
        } else if (genero == GENERO_F) {
            numGeneroF++;
        } else if (genero == GENERO_O) {
            numGeneroO++;
        }
    }

    float mediaNotas = somaNotas / numAlunos;
    float porcentagemAprovados = 100.0 * numAprovados / numAlunos;
    float porcentagemGeneroM = 100.0 * numGeneroM / numAlunos;
    float porcentagemGeneroF = 100.0 * numGeneroF / numAlunos;
    float porcentagemGeneroO = 100.0 * numGeneroO / numAlunos;

    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcentagemAprovados);
    puts("Porcentagem de cada genero:");
    printf("Masculino: %.2f%%\n", porcentagemGeneroM);
    printf("Feminino: %.2f%%\n", porcentagemGeneroF);
    printf("Outro: %.2f%%\n", porcentagemGeneroO);
}
