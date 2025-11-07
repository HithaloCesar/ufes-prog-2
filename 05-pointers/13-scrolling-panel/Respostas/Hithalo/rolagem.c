#define _DEFAULT_SOURCE

#include "rolagem.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim) {
    char mensagens[NUM_MAX_MSGS][TAM_MAX_MSG];

    int numMsgs = 0;
    FuncMsg(mensagens, &numMsgs);

    char mensagensConcatenadas[NUM_MAX_MSGS * TAM_MAX_MSG] = "";
    for (int i = 0; i < numMsgs; i++) {
        strcat(mensagensConcatenadas, mensagens[i]);
        strcat(mensagensConcatenadas, " ");
    }

    int len = strlen(mensagensConcatenadas);

    for (int i = 0; i < tempoFim; i++) {
        for (int j = 0 + i; j < tamanhoDisplay + i; j++) {
            putchar(mensagensConcatenadas[j % len]);
        }
        putchar('\n');

        printf("\033[H\033[J"); // Clear terminal

        if (isatty(STDOUT_FILENO)) {
            usleep(100000); // 0.1 s
        }
    }
}
