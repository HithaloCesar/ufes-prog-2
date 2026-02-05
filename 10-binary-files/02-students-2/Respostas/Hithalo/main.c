#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base_alunos.h"
#include "aluno.h"

int main(void) {
    char *path;
    scanf(" %m[^\n]", &path);

    tBaseAlunos *baseAlunos = CriarBaseAlunos();

    LerBaseAlunos(baseAlunos, path);

    float coeficiente = GetCoeficienteRendimentoMedioBaseAlunos(baseAlunos);

    printf(
        "Coeficiente de Rendimento Medio da base de alunos: %.2f\n",
        coeficiente
    );

    free(path);
    DestruirBaseAlunos(baseAlunos);

    return EXIT_SUCCESS;
}
