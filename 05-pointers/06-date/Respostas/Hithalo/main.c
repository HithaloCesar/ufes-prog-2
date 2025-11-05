#include <stdlib.h>
#include <stdio.h>
#include "data.h"

int main(void) {
    tData data;
    tData dataIni;
    tData dataFim;

    LeData(&dataIni);
    LeData(&dataFim);

    data = dataIni;
    while (!EhIgual(&data, &dataFim)) {
        ImprimeData(&data);
        putchar('\n');

        AvancaParaDiaSeguinte(&data);
    }

    return EXIT_SUCCESS;
}
