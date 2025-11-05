#include <stdlib.h>
#include <stdio.h>
#include "pessoa.h"

#define MAX_PESSOAS 32

int main(void) {
    int numPessoas;
    scanf("%d", &numPessoas);

    tPessoa pessoas[MAX_PESSOAS];

    for (int i = 0; i < numPessoas; i++) {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas, numPessoas);

    for (int i = 0; i < numPessoas; i++) {
        ImprimePessoa(&pessoas[i]);
    }

    return EXIT_SUCCESS;
}
