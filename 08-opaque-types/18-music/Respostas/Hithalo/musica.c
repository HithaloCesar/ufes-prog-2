#include "musica.h"

struct musica {
    char *name;
    char *artist;
    char *album;
    char *genre;
};

Musica *criaMusica(void) {
    Musica *music = malloc(sizeof(*music));
    if (music == NULL) {
        return NULL;
    }

    music->name = NULL;
    music->artist = NULL;
    music->album = NULL;
    music->genre = NULL;

    return music;
}

void leMusica(Musica *music) {
    music->name = malloc(MAX_TAM_STRING * sizeof(*music->name) + 1);
    music->artist = malloc(MAX_TAM_STRING * sizeof(*music->artist) + 1);
    music->album = malloc(MAX_TAM_STRING * sizeof(*music->album) + 1);
    music->genre = malloc(MAX_TAM_STRING * sizeof(*music->genre) + 1);

    if (
        music->name == NULL || music->artist == NULL
        || music->album == NULL || music->genre == NULL
    ) {
        exit(1);
    }

    scanf(" %[^\r\n]", music->name);
    scanf(" %[^\r\n]", music->artist);
    scanf(" %[^\r\n]", music->album);
    scanf(" %[^\r\n]", music->genre);
}

int comparaMusicas(Musica *music_1, Musica *music_2) {
    if (!comparaNomeMus(music_1, music_2->name)) {
        return 0;
    }
    if (!comparaArtistaMus(music_1, music_2->artist)) {
        return 0;
    }

    return 1;
}

int comparaNomeMus(Musica *music, char *name) {
    return !strcmp(music->name, name);
}

int comparaArtistaMus(Musica *music, char *artist) {
    return !strcmp(music->artist, artist);
}

int comparaAlbumMus(Musica *music, char *album) {
    return !strcmp(music->album, album);
}

int comparaGeneroMus(Musica *music, char *genre) {
    return !strcmp(music->genre, genre);
}

void imprimeMusica(Musica *music) {
    printf(
        "%s - %s ............ %s\n",
        music->name, music->artist, music->album
    );
}

void imprimeMusica_Album(Musica *music) {
    printf("%s\n", music->name);
}

void imprimeMusica_Artista(Musica *music) {
    printf("%s - %s\n", music->name, music->album);
}

void imprimeMusica_Genero(Musica *music) {
    printf("%s - %s\n", music->name, music->artist);
}

void apagaMusica(Musica *music) {
    free(music->name);
    free(music->artist);
    free(music->album);
    free(music->genre);
    free(music);
}
