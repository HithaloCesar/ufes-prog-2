#include <stdlib.h>
#include "vector.h"

#define DEFAULT_VECTOR_SIZE 4

struct Vector {
    DataType *data;
    int size;
    int len;
};

Vector *VectorConstruct(void) {
    Vector *v = calloc(1, sizeof(*v));

    return v;
}

void VectorPushBack(Vector *v, DataType val) {
    if (v->len == v->size) {
        if (v->size == 0) {
            v->size = DEFAULT_VECTOR_SIZE;
        } else {
            v->size *= 2;
        }
        v->data = realloc(v->data, v->size * sizeof(*v->data));
    }

    v->data[v->len++] = val;
}

DataType VectorPopFront(Vector *v) {
    DataType d = v->data[0];

    for (int i = 0; i < v->len - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->len--;
    v->data[v->len] = NULL;

    return d;
}

DataType VectorGet(Vector *v, int i) {
    return v->data[i];
}

int VectorSize(Vector *v) {
    return v->len;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    for (int i = 0; i < v->len; i++) {
        destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}
