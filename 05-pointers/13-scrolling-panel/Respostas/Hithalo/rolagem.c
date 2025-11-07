#define _DEFAULT_SOURCE // For usleep (deprecated, but enough for this)

#include "rolagem.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void RolaMsg(
    FptrMsg FuncMsg,
    int tamanhoDisplay,
    int tempoFim,
    void *dadosUsuario
) {
    char msgs[NUM_MAX_MSGS][TAM_MAX_MSG];
    int numMsgs;

    FuncMsg(msgs, &numMsgs, dadosUsuario);

    char mensagensConcatenadas[NUM_MAX_MSGS * TAM_MAX_MSG] = "";
    for (int i = 0; i < numMsgs; i++) {
        strcat(mensagensConcatenadas, msgs[i]);
        strcat(mensagensConcatenadas, " ");
    }

    int len = strlen(mensagensConcatenadas);

    printf("\033[H\033[J"); // Clear terminal. Before start, then each "frame".
    // The statement says it must be printed in the output file, even if it
    // doesn't make sense.

    for (int i = 0; i < tempoFim; i++) {
        for (int j = 0 + i; j < tamanhoDisplay + i; j++) {
            putchar(mensagensConcatenadas[j % len]);
        }
        putchar('\n');

        if (isatty(STDOUT_FILENO)) { // Avoid timeout in autograder.sh
            usleep(100000); // 0.1 s.
        }

        printf("\033[H\033[J");
    }
}
