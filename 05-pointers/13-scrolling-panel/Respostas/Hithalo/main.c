#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rolagem.h"

#define TAMANHO_DISPLAY 30

typedef struct {
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG];
    int numMsgs;
} Mensagens;

void obtemMensagens(
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG],
    int *numMsgs,
    void *dadosUsuario
) {
    Mensagens *msgsOriginais = (Mensagens*)dadosUsuario;

    *numMsgs = msgsOriginais->numMsgs;
    for (int i = 0; i < *numMsgs; i++) {
        strcpy(msg[i], msgsOriginais->msg[i]);
    }
}

int main(void) {
    Mensagens msgs;

    scanf("%d", &msgs.numMsgs);

    for (int i = 0; i < msgs.numMsgs; i++) {
        scanf(" %[^\n]", msgs.msg[i]);
    }

    int tempoFim;
    scanf("%d", &tempoFim);

    RolaMsg(obtemMensagens, TAMANHO_DISPLAY, tempoFim, &msgs);

    return EXIT_SUCCESS;
}
