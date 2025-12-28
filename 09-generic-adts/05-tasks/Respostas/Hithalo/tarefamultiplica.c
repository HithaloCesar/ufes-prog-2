#include "tarefamultiplica.h"

struct mult {
    float n1, n2;
};

tMult *CriaTarefaMultiplicar(float n1, float n2) {
    tMult *mult = calloc(1, sizeof(*mult));

    mult->n1 = n1;
    mult->n2 = n2;

    return mult;
}

void ExecutaTarefaMultiplicar(void *mult) {
    tMult *t = (tMult *)mult;

    float produto = t->n1 * t->n2;
    printf(
        "\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f",
        t->n1, t->n2, produto
    );
}

void DestroiTarefaMultiplicar(void *mult) {
    tMult *t = (tMult *)mult;

    free(t);
}
