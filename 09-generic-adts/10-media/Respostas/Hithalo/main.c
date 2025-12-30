#include <stdlib.h>
#include <stdio.h>
#include "roteiro.h"
#include "midia.h"
#include "pintura.h"
#include "musica.h"
#include "livro.h"

enum Operacao {
    OPERACAO_ADICIONAR_PINTURA = 'P',
    OPERACAO_ADICIONAR_MUSICA = 'M',
    OPERACAO_ADICIONAR_LIVRO = 'L'
};

int main(void) {
    Roteiro *r = roteiro_construct();

    int numMidias;
    scanf("%d", &numMidias);

    for (int i = 0; i < numMidias; i++) {
        char operacao;
        scanf(" %c", &operacao);
        getchar();

        switch (operacao) {
            case OPERACAO_ADICIONAR_PINTURA: {
                Pintura *p = pintura_read_and_construct();
                roteiro_inserir_midia(r, p, pintura_print, pintura_destroy);
                break;
            }
            case OPERACAO_ADICIONAR_MUSICA: {
                Musica *m = musica_read_and_construct();
                roteiro_inserir_midia(r, m, musica_print, musica_destroy);
                break;
            }
            case OPERACAO_ADICIONAR_LIVRO: {
                Livro *l = livro_read_and_construct();
                roteiro_inserir_midia(r, l, livro_print, livro_destroy);
                break;
            }
        }
    }

    roteiro_imprimir_midias(r);

    roteiro_destroy(r);

    return EXIT_SUCCESS;
}
