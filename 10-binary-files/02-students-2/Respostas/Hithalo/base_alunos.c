#include "base_alunos.h"

#include <stdlib.h>

#include "aluno.h"

struct BaseAlunos {
    tAluno **alunos;
    int numAlunos;
};

tBaseAlunos *CriarBaseAlunos(void) {
    tBaseAlunos *baseAlunos = calloc(1, sizeof(*baseAlunos));

    return baseAlunos;
}

void DestruirBaseAlunos(tBaseAlunos *baseAlunos) {
    for (int i = 0; i < baseAlunos->numAlunos; i++) {
        DestruirAluno(baseAlunos->alunos[i]);
    }

    free(baseAlunos->alunos);
    free(baseAlunos);
}

void LerBaseAlunos(tBaseAlunos *baseAlunos, char *nomeArquivo) {
    FILE *arquivo_binario = fopen(nomeArquivo, "rb");

    int numAlunos = 0;
    fread(&numAlunos, sizeof(numAlunos), 1, arquivo_binario);

    baseAlunos->numAlunos = numAlunos;
    baseAlunos->alunos = calloc(numAlunos, sizeof(*baseAlunos->alunos));

    for (int i = 0; i < baseAlunos->numAlunos; i++) {
        baseAlunos->alunos[i] = LeAluno(arquivo_binario);
    }

    fclose(arquivo_binario);
}

float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos *baseAlunos) {
    float soma = 0.0;

    for (int i = 0; i < baseAlunos->numAlunos; i++) {
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    float coeficienteMedio = soma / baseAlunos->numAlunos;

    return coeficienteMedio;
}
