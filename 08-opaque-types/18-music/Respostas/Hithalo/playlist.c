#include "playlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct playlist {
    char name[MAX_TAM_STRING + 1];
    Musica *musicas[TAM_MAX_MUSICAS];
    int qtdMusicas;
};

Playlist *criaPlaylist(char *name) {
    Playlist *playlist = calloc(1, sizeof(*playlist));

    strcpy(playlist->name, name);

    return playlist;
}

void adicionaMusica(Playlist *playlist) {
    Musica *musica = criaMusica();
    leMusica(musica);

    if (playlist->qtdMusicas == TAM_MAX_MUSICAS) {
        printf("PLAYLIST CHEIA!\n");
        apagaMusica(musica);
        return;
    }

    playlist->musicas[playlist->qtdMusicas++] = musica;
}

int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus) {
    for (int i = 0; i < playlist->qtdMusicas; i++) {
        if (comparador(playlist->musicas[i], music)) {
            printf("MUSICA REMOVIDA: ");
            impMus(playlist->musicas[i]);

            apagaMusica(playlist->musicas[i]);

            for (int j = i; j < playlist->qtdMusicas - 1; j++) {
                playlist->musicas[j] = playlist->musicas[j + 1];
            }
            playlist->qtdMusicas--;

            return 1;
        }
    }

    return 0;
}

void impressFunction(
    Playlist *playlist,
    char *key,
    compara comparador,
    tipoImpressaoMusica impMus
) {
    printf("---------------------------------------\n");

    if (comparador == NULL) {
        printf("%s\n", playlist->name);
        putchar('\n');
        for (int i = 0; i < playlist->qtdMusicas; i++) {
            impMus(playlist->musicas[i]);
        }
    } else {
        printf("%s\n", key);
        putchar('\n');
        for (int i = 0; i < playlist->qtdMusicas; i++) {
            if (comparador(playlist->musicas[i], key)) {
                impMus(playlist->musicas[i]);
            }
        }
    }

    printf("---------------------------------------\n");
}

void apagaPlaylist(Playlist *playlist) {
    for (int i = 0; i < playlist->qtdMusicas; i++) {
        apagaMusica(playlist->musicas[i]);
    }

    free(playlist);
}
