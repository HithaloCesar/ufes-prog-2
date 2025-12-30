#include "roteiro.h"
#include <stdlib.h>
#include <stdio.h>

#define MIDIAS_TAM_INICIAL 4

struct Roteiro {
    Midia **midias;
    int numMidias;
    int maxMidias;
};

Roteiro *roteiro_construct(void) {
    Roteiro *r = calloc(1, sizeof(*r));

    return r;
}

void roteiro_inserir_midia(
    Roteiro *r,
    void *dado,
    PrintFunction print_fn,
    FreeFunction free_fn
) {
    if (r->numMidias == r->maxMidias) {
        if (r->maxMidias == 0) {
            r->maxMidias = MIDIAS_TAM_INICIAL;
        } else {
            r->maxMidias *= 2;
        }
        r->midias = realloc(r->midias, r->maxMidias * sizeof(r->midias));
    }

    Midia *m = midia_construct(dado, print_fn, free_fn);

    r->midias[r->numMidias++] = m;
}

void roteiro_imprimir_midias(Roteiro *r) {
    if (r->numMidias == 0) {
        puts("SEM MIDIAS PARA IMPRIMIR");
        return;
    }

    puts("IMPRIMINDO MIDIAS");

    char *sep = "";
    for (int i = 0; i < r->numMidias; i++) {
        printf("%s", sep);

        Midia *m = r->midias[i];
        printf("MIDIA %d: ", i + 1);
        midia_print(m);

        sep = "\n";
    }
}

void roteiro_destroy(Roteiro *r) {
    for (int i = 0; i < r->numMidias; i++) {
        Midia *m = r->midias[i];
        midia_destroy(m);
    }

    free(r->midias);
    free(r);
}
