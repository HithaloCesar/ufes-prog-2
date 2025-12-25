#include <stdlib.h>
#include "computador.h"

int main(void) {
    tComputador *c = CriaComputador();

    GerenciaJogo(c);

    ImprimeRelatorio(c);

    DestroiComputador(c);

    return EXIT_SUCCESS;
}
