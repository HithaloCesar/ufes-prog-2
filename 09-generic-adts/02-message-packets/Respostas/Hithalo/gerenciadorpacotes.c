#include "gerenciadorpacotes.h"
#include <stdlib.h>
#include <stdio.h>

#define QTD_INICIAL_PACOTES 4

struct gerenciadorpacotes {
    tPacote **pacotes;
    int qtdPacotes;
    int maxPacotes;
};

tGerenciador *CriaGerenciador(void) {
    tGerenciador *geren = calloc(1, sizeof(*geren));

    return geren;
}

void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac) {
    if (geren->qtdPacotes == geren->maxPacotes) {
        if (geren->maxPacotes == 0) {
            geren->maxPacotes = QTD_INICIAL_PACOTES;
        } else {
            geren->maxPacotes *= 2;
        }
        geren->pacotes = realloc(geren->pacotes, geren->maxPacotes * sizeof(*geren->pacotes));
    }

    geren->pacotes[geren->qtdPacotes++] = pac;
}

void DestroiGerenciador(tGerenciador *geren) {
    for (int i = 0; i < geren->qtdPacotes; i++) {
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador *geren, int idx) {
    ImprimePacote(geren->pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador *geren) {
    for (int i = 0; i < geren->qtdPacotes; i++) {
        ImprimePacote(geren->pacotes[i]);
    }
}
