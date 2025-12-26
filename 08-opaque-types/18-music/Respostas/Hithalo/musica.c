#include "musica.h"

struct musica {
    char name[MAX_TAM_STRING + 1];
    char artist[MAX_TAM_STRING + 1];
    char album[MAX_TAM_STRING + 1];
    char genre[MAX_TAM_STRING + 1];
};

Musica *criaMusica(void) {
    Musica *music = calloc(1, sizeof(*music));

    return music;
}

void leMusica(Musica *music) {
    scanf(" %[^\n]", music->name);
    scanf(" %[^\n]", music->artist);
    scanf(" %[^\n]", music->album);
    scanf(" %[^\n]", music->genre);
    getchar();
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
    free(music);
}
