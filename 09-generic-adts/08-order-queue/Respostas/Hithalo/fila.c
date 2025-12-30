#include "fila.h"
#include <stdlib.h>

struct Fila {
    Vector *v;
};

Fila *FilaConstruct(void) {
    Fila *f = calloc(1, sizeof(*f));

    f->v = VectorConstruct();

    return f;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType)) {
    VectorDestroy(f->v, destroy);
    free(f);
}

int FilaSize(Fila *f) {
    return VectorSize(f->v);
}

DataType FilaPop(Fila *f) {
    return VectorPopFront(f->v);
}

void FilaPush(Fila *f, DataType val) {
    VectorPushBack(f->v, val);
}
