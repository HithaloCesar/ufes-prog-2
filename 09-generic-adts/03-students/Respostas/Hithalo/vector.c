#include "vector.h"
#include <stdlib.h>

#define DEFAULT_VECTOR_SIZE 4

struct Vector {
    data_type *data;
    int len;
    int size;
};

Vector *VectorConstruct(void) {
    Vector *v = calloc(1, sizeof(*v));

    return v;
}

void VectorPushBack(Vector *v, data_type val) {
    if (v->len >= v->size) {
        if (v->size == 0) {
            v->size = DEFAULT_VECTOR_SIZE;
        } else {
            v->size *= 2;
        }
        v->data = realloc(v->data, v->size * sizeof(*v->data));
    }
    v->data[v->len++] = val;
}

data_type VectorGet(Vector *v, int i) {
    return v->data[i];
}

int VectorSize(Vector *v) {
    return v->len;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    for (int i = 0; i < v->len; i++) {
        destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}
