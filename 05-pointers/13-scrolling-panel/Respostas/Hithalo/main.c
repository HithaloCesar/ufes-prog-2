#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rolagem.h"

#define TAMANHO_DISPLAY 30

void leMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs) {
    scanf("%d", numMsgs);
    for (int i = 0; i < *numMsgs; i++) {
        scanf(" %[^\n]", msg[i]);
    }
}

int main(void) {
    int tempoFim;
    scanf("%d", &tempoFim);

    RolaMsg(leMensagens, TAMANHO_DISPLAY, tempoFim);

    return EXIT_SUCCESS;
}
