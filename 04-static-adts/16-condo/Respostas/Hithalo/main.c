#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "reserva.h"

#define MAX_MORADORES 100
#define MAX_AREAS 10
#define MAX_RESERVAS 100

static int buscaIndiceMorador(
    Morador moradores[],
    int numMoradores,
    char cpf[]
);

static int buscaIndiceArea(
    Area areas[],
    int numAreas,
    char id[]
);

int main(void) {
    int numAreas;
    scanf("%d\n", &numAreas);

    Area areas[MAX_AREAS];
    for (int i = 0; i < numAreas; i++) {
        areas[i] = lerArea();
    }

    int numMoradores;
    scanf("%d\n", &numMoradores);

    Morador moradores[MAX_MORADORES];
    for (int i = 0; i < numMoradores; i++) {
        moradores[i] = lerMorador();
    }

    Reserva reservas[MAX_RESERVAS];
    int numReservas = 0;

    int numTentativasDeReserva;
    scanf("%d\n", &numTentativasDeReserva);
    for (int i = 0; i < numTentativasDeReserva; i++) {
        char idArea[MAX_TAM_ID] = "";
        char cpf[MAX_TAM_CPF] = "";
        Data data = {0};
        int qtdConv = 0;
        char turno = 0;

        lerDadosSolicitacaoReserva(idArea, cpf, &data, &qtdConv, &turno);

        int indiceMorador = buscaIndiceMorador(moradores, numMoradores, cpf);

        if (indiceMorador == -1) {
            continue;
        }

        int indiceArea = buscaIndiceArea(areas, numAreas, idArea);

        bool reservaValida = verificaSolicitacaoReserva(
            reservas,
            numReservas,
            moradores[indiceMorador],
            areas[indiceArea],
            data,
            qtdConv,
            turno
        );

        if (reservaValida) {
            reservas[numReservas] = criaReserva(
                moradores[indiceMorador],
                areas[indiceArea],
                data,
                qtdConv,
                turno
            );
            imprimeReserva(reservas[numReservas]);
            numReservas++;
        }
    }

    return EXIT_SUCCESS;
}

static int buscaIndiceMorador(
    Morador moradores[],
    int numMoradores,
    char cpf[]
) {
    for (int i = 0; i < numMoradores; i++) {
        if (verificaCPFMorador(moradores[i], cpf)) {
            return i;
        }
    }

    return -1;
}

static int buscaIndiceArea(
    Area areas[],
    int numAreas,
    char id[]
) {
    for (int i = 0; i < numAreas; i++) {
        if (verificaIdArea(areas[i], id)) {
            return i;
        }
    }

    return -1;
}
