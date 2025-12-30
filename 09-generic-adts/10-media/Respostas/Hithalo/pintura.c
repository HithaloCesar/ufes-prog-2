#include "pintura.h"
#include <stdlib.h>
#include <stdio.h>

struct Pintura {
    char titulo[MAXTAM_STRINGS + 1];
    char artista[MAXTAM_STRINGS + 1];
    char movimento[MAXTAM_STRINGS + 1];
    char material[MAXTAM_STRINGS + 1];
    int ano_de_finalizacao;
};

Pintura *pintura_read_and_construct(void) {
    Pintura *pintura = calloc(1, sizeof(*pintura));

    scanf(" %s", pintura->titulo);
    scanf(" %s", pintura->artista);
    scanf(" %s", pintura->movimento);
    scanf(" %s", pintura->material);
    scanf("%d", &pintura->ano_de_finalizacao);
    getchar();

    return pintura;
}

void pintura_print(void *p) {
    Pintura *pintura = (Pintura *)p;

    puts("PINTURA");
    printf("Titulo: %s\n", pintura->titulo);
    printf("Artista: %s\n", pintura->artista);
    printf("Movimento: %s\n", pintura->movimento);
    printf("Material: %s\n", pintura->material);
    printf("Ano: %d\n", pintura->ano_de_finalizacao);
}

void pintura_destroy(void *p) {
    free(p);
}
