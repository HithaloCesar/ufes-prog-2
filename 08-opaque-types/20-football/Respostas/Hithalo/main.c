#include <stdlib.h>
#include "brasileirao.h"

int main(void) {
    BRA *br = CriaCamp();

    RealizaCamp(br);

    FinalizaCamp(br);

    return EXIT_SUCCESS;
}
