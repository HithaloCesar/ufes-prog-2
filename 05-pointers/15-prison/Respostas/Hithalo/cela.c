#include "cela.h"
#include <stdio.h>
#include <stdbool.h>

tCela criaCela(int capacidade) {
    tCela cela;
    cela.nPresidiarios = 0;
    cela.capacidade = capacidade;

    return cela;
}

int possuiVagaCela(tCela *cela) {
    return cela->nPresidiarios < cela->capacidade;
}

int obtemNumeroPrisioneirosCela(tCela *cela) {
    return cela->nPresidiarios;
}

void inserePrisioneiroCela(tCela *cela, tPrisioneiro prisioneiro) {
    cela->prisioneiros[cela->nPresidiarios++] = prisioneiro;
}

tPrisioneiro obtemPrisioneiroCela(tCela *cela, int i) {
    return cela->prisioneiros[i];
}

void fogePrisioneirosCela(tCela *cela) {
    for (int i = 0; i < cela->nPresidiarios; i++) {
        fogePrisioneiro(&cela->prisioneiros[i]);
    }

    cela->nPresidiarios = 0;
}

void passaDiaCela(tCela *cela) {
    for (int i = 0; i < cela->nPresidiarios; i++) {
        passaTempoPrisioneiro(&cela->prisioneiros[i]);
        if (acabouPenaPrisioneiro(&cela->prisioneiros[i])) {
            liberaPrisioneiroCumpriuPena(&cela->prisioneiros[i]);

            for (int j = i; j < cela->nPresidiarios - 1; j++) {
                cela->prisioneiros[j] = cela->prisioneiros[j + 1];
            }

            i--;
            cela->nPresidiarios--;
        }
    }
}
