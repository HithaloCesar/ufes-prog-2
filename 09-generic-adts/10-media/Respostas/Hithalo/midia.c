#include "midia.h"
#include <stdlib.h>

struct Midia {
    void *dado;
    PrintFunction printf_fn;
    FreeFunction free_fn;
};

Midia *midia_construct(
    void *dado,
    PrintFunction print_fn,
    FreeFunction free_fn
) {
    Midia *m = calloc(1, sizeof(*m));

    m->dado = dado;
    m->printf_fn = print_fn;
    m->free_fn = free_fn;

    return m;
}

void midia_print(Midia* m) {
    m->printf_fn(m->dado);
}

void midia_destroy(Midia* m) {
    m->free_fn(m->dado);
    free(m);
}
