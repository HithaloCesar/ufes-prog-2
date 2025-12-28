#include <stdlib.h>
#include <stdio.h>
#include "tadgen.h"

int main(void) {
    puts("tad_gen_01");

    puts("Digite o tipo e numero de elementos:");

    int tipo, numElem;
    scanf("%d %d", &tipo, &numElem);

    tGeneric *gen = CriaGenerico(tipo, numElem);

    LeGenerico(gen);

    ImprimeGenerico(gen);

    DestroiGenerico(gen);

    return EXIT_SUCCESS;
}
