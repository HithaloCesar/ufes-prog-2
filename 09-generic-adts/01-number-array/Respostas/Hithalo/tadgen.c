#include "tadgen.h"
#include <stdlib.h>
#include <stdio.h>

struct generic {
    void *elementos;
    int numElem;
    Type tipoElem;
};

tGeneric *CriaGenerico(Type type, int numElem) {
    tGeneric *gen = calloc(1, sizeof(*gen));

    gen->tipoElem = type;
    gen->numElem = numElem;

    switch (gen->tipoElem) {
        case INT: {
            gen->elementos = calloc(gen->numElem, sizeof(int));
            break;
        }
        case FLOAT: {
            gen->elementos = calloc(gen->numElem, sizeof(float));
            break;
        }
    }

    return gen;
}

void DestroiGenerico(tGeneric *gen) {
    free(gen->elementos);
    free(gen);
}

void LeGenerico(tGeneric *gen) {
    putchar('\n');
    puts("Digite o vetor:");

    for (int i = 0; i < gen->numElem; i++) {
        switch (gen->tipoElem) {
            case INT: {
                scanf("%d", &((int *)gen->elementos)[i]);
                break;
            }
            case FLOAT: {
                scanf("%f", &((float *)gen->elementos)[i]);
                break;
            }
        }
    }

    getchar();
}

void ImprimeGenerico(tGeneric *gen) {
    char *sep = "";
    for (int i = 0; i < gen->numElem; i++) {
        switch (gen->tipoElem) {
            case INT: {
                printf("%s%d", sep, ((int*)gen->elementos)[i]);
                break;
            }
            case FLOAT: {
                printf("%s%.2f", sep, ((float*)gen->elementos)[i]);
                break;
            }
        }
        sep = " ";
    }

    putchar('\n');
}
