#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"
#include "vector.h"
#include "relatorio.h"

int main(void) {
    Vector *v = VectorConstruct();

    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    getchar();

    for (int i = 0; i < qtdAlunos; i++) {
        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(v, (data_type)a);
    }

    ImprimeRelatorio(v);

    VectorDestroy(v, DestroiAluno);

    return EXIT_SUCCESS;
}
