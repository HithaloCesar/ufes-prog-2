#include <stdlib.h>
#include <stdio.h>
#include "servidor.h"

int main(void) {
    Servidor s = leRegistrosServidor();
    criaRelatorioServidor(s);

    return EXIT_SUCCESS;
}
