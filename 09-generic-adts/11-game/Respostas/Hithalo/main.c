#include <stdlib.h>
#include <stdio.h>

#include "tAmbiente.h"
#include "tMonitorador.h"
#include "tEventoMovimento.h"
#include "tEventoClique.h"

typedef enum modo {
    MODO_WASD = 1,
    MODO_UHJK,
    MODO_WASD_UHJK
} tModo;

int main(void) {
    tAmbiente *amb = criaAmbiente();
    tMonitorador *monitorador = criaMonitorador();

    int modo;
    scanf("%d", &modo);
    getchar();

    printf("Modo %d selecionado!\n", modo);

    if (modo == MODO_WASD || modo == MODO_WASD_UHJK) {
        tEventoMovimento *evMovWasd = criaEventoMovimento("WASD");
        adicionaElementoMonitorador(
            monitorador,
            evMovWasd,
            processaEventoMovimento,
            identificaEventoMovimento,
            liberaEventoMovimento
        );
    }

    if (modo == MODO_UHJK || modo == MODO_WASD_UHJK) {
        tEventoMovimento *evMovUhjk = criaEventoMovimento("UHJK");
        adicionaElementoMonitorador(
            monitorador,
            evMovUhjk,
            processaEventoMovimento,
            identificaEventoMovimento,
            liberaEventoMovimento
        );
    }

    tEventoClique *evClique = criaEventoClique("LRM");
    adicionaElementoMonitorador(
        monitorador,
        evClique,
        processaEventoClique,
        identificaEventoClique,
        liberaEventoClique
    );

    iniciaMonitoramentotMonitorador(amb, monitorador);

    liberaAmbiente(amb);
    liberaMonitorador(monitorador);

    return EXIT_SUCCESS;
}
