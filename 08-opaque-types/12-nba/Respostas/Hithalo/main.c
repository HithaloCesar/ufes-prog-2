#include <stdlib.h>
#include "nba.h"

int main(void) {
    tNBA nba = CriaNBA();

    nba = RodaNBA(nba);
    ImprimeRelatorioNBA(nba);

    LiberaNBA(nba);

    return EXIT_SUCCESS;
}
