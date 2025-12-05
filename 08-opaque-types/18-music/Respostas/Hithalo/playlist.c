#include "playlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct playlist {
    char *name;
    Musica **musicas;
    size_t tamanhoMusicas; // remover
    size_t qtdMusicas; // remover
};

Playlist *criaPlaylist(char *name) {
    Playlist *playlist = malloc(sizeof(*playlist));
    if (playlist == NULL) {
        return NULL;
    }

    playlist->name = malloc(MAX_TAM_STRING * sizeof(*playlist->name));
    if (playlist->name == NULL) {
        free(playlist);
        return NULL;
    }

    playlist->musicas = malloc(TAM_MAX_MUSICAS * sizeof(*playlist->musicas));
    if (playlist->musicas == NULL) {
        free(playlist->name);
        free(playlist);
        return NULL;
    }

    strcpy(playlist->name, name);
    playlist->tamanhoMusicas = TAM_MAX_MUSICAS;
    playlist->qtdMusicas = 0;

    return playlist;
}

void adicionaMusica(Playlist *playlist) {
    Musica *musica = criaMusica();
    leMusica(musica);
    if (playlist->qtdMusicas == playlist->tamanhoMusicas) {
        printf("PLAYLIST CHEIA!\n");
        apagaMusica(musica);
        return;
    }
    playlist->musicas[playlist->qtdMusicas++] = musica;
}

int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus) {
    for (size_t i = 0; i < playlist->tamanhoMusicas; i++) {
        if (comparador(playlist->musicas[i], music)) {
            printf("MUSICA REMOVIDA: ");
            impMus(playlist->musicas[i]);
            apagaMusica(playlist->musicas[i]);
            for (size_t j = i; j < playlist->tamanhoMusicas - 1; j++) {
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
        for (size_t i = 0; i < playlist->qtdMusicas; i++) {
            impMus(playlist->musicas[i]);
        }
    } else {
        printf("%s\n", key);
        putchar('\n');
        for (size_t i = 0; i < playlist->qtdMusicas; i++) {
            if (comparador(playlist->musicas[i], key)) {
                impMus(playlist->musicas[i]);
            }
        }
    }
    printf("---------------------------------------\n");
}

void apagaPlaylist(Playlist *playlist) {
    free(playlist->name);
    for (size_t i = 0; i < playlist->qtdMusicas; i++) {
        apagaMusica(playlist->musicas[i]);
    }
    free(playlist->musicas);
    free(playlist);
}
