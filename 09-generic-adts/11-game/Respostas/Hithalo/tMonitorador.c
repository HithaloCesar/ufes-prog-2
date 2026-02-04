#include "tMonitorador.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "tAmbiente.h"

#define MONITORADOR_TAM_MIN_EVENTOS 1

typedef struct evento {
    void *evento;
    FptrProcessaEvento funcPE;
    FptrIdentificaEvento funcId;
    FptrLiberaEvento funcLE;
} tEvento;

struct _tMonitorador {
    tEvento **eventos;
    int tamEventos;
    int numEventos;
};

tMonitorador* criaMonitorador() {
    tMonitorador *m = calloc(1, sizeof(*m));

    return m;
}

void liberaMonitorador(tMonitorador* m) {
    for (int i = 0; i < m->numEventos; i++) {
        m->eventos[i]->funcLE(m->eventos[i]->evento);
        free(m->eventos[i]);
    }

    free(m->eventos);
    free(m);
}

void adicionaElementoMonitorador(
    tMonitorador* m,
    void* e,
    FptrProcessaEvento funcPE,
    FptrIdentificaEvento funcId,
    FptrLiberaEvento funcLE
) {
    if (m->numEventos == m->tamEventos) {
        if (m->tamEventos == 0) {
            m->tamEventos = MONITORADOR_TAM_MIN_EVENTOS;
        } else {
            m->tamEventos *= 2;
        }

        m->eventos = realloc(m->eventos, m->tamEventos * sizeof(*m->eventos));
    }

    tEvento *evento = calloc(1, sizeof(*evento));
    evento->evento = e;
    evento->funcPE = funcPE;
    evento->funcId = funcId;
    evento->funcLE = funcLE;

    m->eventos[m->numEventos++] = evento;
}

void iniciaMonitoramentotMonitorador(tAmbiente* amb, tMonitorador* m) {
    while (true) {
        char c;
        scanf(" %c", &c);
        getchar();

        bool eventoOn = false;
        for (int i = 0; i < m->numEventos; i++) {
            eventoOn = m->eventos[i]->funcId(m->eventos[i]->evento, c) != 0;

            if (eventoOn) {
                m->eventos[i]->funcPE(amb, m->eventos[i]->evento, c);
                break;
            }
        }

        if (!eventoOn) {
            return;
        }
    }
}
