#include "musica.h"
#include <stdlib.h>
#include <stdio.h>

struct Musica {
    char titulo[MAXTAM_STRINGS + 1];
    char artista[MAXTAM_STRINGS + 1];
    char album[MAXTAM_STRINGS + 1];
    char genero[MAXTAM_STRINGS + 1];
    char (*membros)[MAXTAM_STRINGS + 1];
    int numMembros;
};

Musica *musica_read_and_construct(void) {
    Musica *musica = calloc(1, sizeof(*musica));

    scanf(" %s", musica->titulo);
    scanf(" %s", musica->artista);
    scanf("%d", &musica->numMembros);

    musica->membros = calloc(musica->numMembros, sizeof(*musica->membros));
    for (int i = 0; i < musica->numMembros; i++) {
        scanf(" %s", musica->membros[i]);
    }

    scanf(" %s", musica->album);
    scanf(" %s", musica->genero);
    getchar();

    return musica;
}

void musica_print(void *m) {
    Musica *musica = (Musica *)m;

    puts("MUSICA");
    printf("%s - %s (feat.", musica->artista, musica->titulo);
    char *sep = "";
    for (int i = 0; i < musica->numMembros; i++) {
        printf("%s %s", sep, musica->membros[i]);
        sep = ",";
    }
    puts(")");
    printf("Album: %s\n", musica->album);
    printf("Genero: %s\n", musica->genero);
}

void musica_destroy(void *m) {
    Musica *musica = (Musica *)m;

    free(musica->membros);
    free(musica);
}
