#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rolagem.h"

#define TAMANHO_DISPLAY 30

// Unfortunately, static global variables are needed, since the header can't be
// changed

static int g_numMsgs;
static char g_msgs[NUM_MAX_MSGS][TAM_MAX_MSG];

void obtemMensagens(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int *numMsgs) {
    *numMsgs = g_numMsgs;
    for (int i = 0; i < *numMsgs; i++) {
        strcpy(msg[i], g_msgs[i]);
    }
}

int main(void) {
    scanf("%d", &g_numMsgs);

    for (int i = 0; i < g_numMsgs; i++) {
        scanf(" %[^\n]", g_msgs[i]);
    }

    int tempoFim;
    scanf("%d", &tempoFim);

    RolaMsg(obtemMensagens, TAMANHO_DISPLAY, tempoFim);

    return EXIT_SUCCESS;
}
