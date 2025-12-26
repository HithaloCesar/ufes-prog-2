#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "playlist.h"

typedef enum {
    OPERACAO_ADICONAR_MUSICA = 1,
    OPERACAO_REMOVER_MUSICA,
    OPERACAO_IMPRIMIR_PLAYLIST,
    OPERACAO_IMPRIMIR_MUSICAS_ARTISTA,
    OPERACAO_IMPRIMIR_MUSICAS_ALBUM,
    OPERACAO_IMPRIMIR_MUSICAS_GENERO
} Operacao;

static void operacaoAdicionarMusica(Playlist *p);
static void operacaoRemoverMusica(Playlist *p);
static void operacaoImprimirPlaylist(Playlist *p);
static void operacaoImprimirMusicasArtista(Playlist *p);
static void operacaoImprimirMusicasAlbum(Playlist *p);
static void operacaoImprimirMusicasGenero(Playlist *p);

int main(void) {
    char playlist_name[MAX_TAM_STRING];
    scanf(" %[^\n]", playlist_name);

    Playlist *playlist = criaPlaylist(playlist_name);

    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);

    for (int i = 0; i < qtdOperacoes; i++) {
        int operacao;
        scanf("%d", &operacao);
        getchar();

        switch (operacao) {
            case OPERACAO_ADICONAR_MUSICA: {
                operacaoAdicionarMusica(playlist);
                break;
            }
            case OPERACAO_REMOVER_MUSICA: {
                operacaoRemoverMusica(playlist);
                break;
            }
            case OPERACAO_IMPRIMIR_PLAYLIST: {
                operacaoImprimirPlaylist(playlist);
                break;
            }
            case OPERACAO_IMPRIMIR_MUSICAS_ARTISTA: {
                operacaoImprimirMusicasArtista(playlist);
                break;
            }
            case OPERACAO_IMPRIMIR_MUSICAS_ALBUM: {
                operacaoImprimirMusicasAlbum(playlist);
                break;
            }
            case OPERACAO_IMPRIMIR_MUSICAS_GENERO: {
                operacaoImprimirMusicasGenero(playlist);
                break;
            }
        }
    }

    apagaPlaylist(playlist);

    return EXIT_SUCCESS;
}

static void operacaoAdicionarMusica(Playlist *p) {
    adicionaMusica(p);
}

static void operacaoRemoverMusica(Playlist *p) {
    char music[MAX_TAM_STRING];
    scanf(" %[^\n]", music);
    getchar();

    bool sucesso = removeMusica(p, music, comparaNomeMus, imprimeMusica_Album);

    if (!sucesso) {
        printf("A MUSICA NAO ESTA NA PLAYLIST\n");
    }
}

static void operacaoImprimirPlaylist(Playlist *p) {
    impressFunction(p, NULL, NULL, imprimeMusica);
}

static void operacaoImprimirMusicasArtista(Playlist *p) {
    char artist[MAX_TAM_STRING];
    scanf(" %[^\n]", artist);
    getchar();

    impressFunction(p, artist, comparaArtistaMus, imprimeMusica_Artista);
}

static void operacaoImprimirMusicasAlbum(Playlist *p) {
    char album[MAX_TAM_STRING];
    scanf(" %[^\n]", album);
    getchar();

    impressFunction(p, album, comparaAlbumMus, imprimeMusica_Album);
}

static void operacaoImprimirMusicasGenero(Playlist *p) {
    char genre[MAX_TAM_STRING];
    scanf(" %[^\n]", genre);
    getchar();

    impressFunction(p, genre, comparaGeneroMus, imprimeMusica_Genero);
}
