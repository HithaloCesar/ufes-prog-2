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

static void operacaoAdicionarMusica(Playlist *p) {
    adicionaMusica(p);
}

static void operacaoRemoverMusica(Playlist *p) {
    char music[MAX_TAM_STRING];
    scanf(" %[^\r\n]\n", music);

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
    scanf(" %[^\r\n]\n", artist);

    impressFunction(p, artist, comparaArtistaMus, imprimeMusica_Artista);
}

static void operacaoImprimirMusicasAlbum(Playlist *p) {
    char album[MAX_TAM_STRING];
    scanf(" %[^\r\n]\n", album);

    impressFunction(p, album, comparaAlbumMus, imprimeMusica_Album);
}

static void operacaoImprimirMusicasGenero(Playlist *p) {
    char genre[MAX_TAM_STRING];
    scanf(" %[^\r\n]\n", genre);

    impressFunction(p, genre, comparaGeneroMus, imprimeMusica_Genero);
}

int main(void) {
    char playlist_name[MAX_TAM_STRING];
    scanf(" %[^\r\n]\n", playlist_name);

    Playlist *playlist = criaPlaylist(playlist_name);

    int qtdOperacoes;
    scanf("%d\n", &qtdOperacoes);

    for (int i = 0; i < qtdOperacoes; i++) {
        int operacao;
        scanf("%d\n", &operacao);

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
            default: {
                break;
            }
        }
    }

    apagaPlaylist(playlist);

    return EXIT_SUCCESS;
}
