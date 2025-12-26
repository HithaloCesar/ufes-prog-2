#include <stdlib.h>
#include "cidade.h"

int main(void) {
    tCidade cidade = CriaCidade();

    LeEntrada(cidade);

    ProcessaAtaques(cidade);

    ImprimeDados(cidade);

    LiberaCidade(cidade);

    return EXIT_SUCCESS;
}
