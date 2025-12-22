#include <stdlib.h>
#include "dracomania.h"

int main(void) {
    tDracomania d = CriaDracomania();

    d = RodaDracomania(d);

    ImprimeRelatorioDracomania(d);

    LiberaDracomania(d);

    return EXIT_SUCCESS;
}
