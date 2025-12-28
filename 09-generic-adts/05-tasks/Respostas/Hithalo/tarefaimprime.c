#include "tarefaimprime.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct impr {
    char *msg;
};

tImpr *CriaTarefaImprimir(char *msg) {
    tImpr *imp = calloc(1, sizeof(*imp));

    int msgLen = strlen(msg);
    imp->msg = calloc(msgLen + 1, sizeof(*imp->msg));

    strcpy(imp->msg, msg);

    return imp;
}

void ExecutaTarefaImprimir(void *imp) {
    tImpr *t = (tImpr *)imp;
    printf("\n%s", t->msg);
}

void DestroiTarefaImprimir(void *imp) {
    tImpr *t = (tImpr *)imp;
    free(t->msg);
    free(t);
}
