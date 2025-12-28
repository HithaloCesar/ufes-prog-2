#include "tarefasoma.h"
#include <stdlib.h>
#include <stdio.h>

struct soma {
    float n1, n2;
};

tSoma *CriaTarefaSoma(float n1, float n2) {
    tSoma *sum = calloc(1, sizeof(*sum));

    sum->n1 = n1;
    sum->n2 = n2;

    return sum;
}

void ExecutaTarefaSoma(void *sum) {
    tSoma *t = (tSoma *)sum;

    float soma = t->n1 + t->n2;
    printf(
        "\nO resultado da soma de %.2f com %.2f eh: %.2f",
        t->n1, t->n2, soma
    );
}

void DestroiTarefaSoma(void *sum) {
    tSoma *t = (tSoma *)sum;

    free(t);
}
