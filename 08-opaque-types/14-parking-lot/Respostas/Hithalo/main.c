#include <stdlib.h>
#include "sistema.h"

int main(void) {
    tSistema *sys = CriaSistema();

    LeSistema(sys);

    ImprimeFaturamentoSistema(sys);

    DestroiSistema(sys);

    return EXIT_SUCCESS;
}
