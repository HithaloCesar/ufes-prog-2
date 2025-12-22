#include <stdlib.h>
#include "eleicao.h"

int main(void) {
    tEleicao *eleicao = InicializaEleicao();

    RealizaEleicao(eleicao);

    ImprimeResultadoEleicao(eleicao);

    ApagaEleicao(eleicao);

    return EXIT_SUCCESS;
}
