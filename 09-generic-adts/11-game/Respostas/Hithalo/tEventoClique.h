#ifndef _EVENTOCLIQUE_H_
#define _EVENTOCLIQUE_H_

#include "tAmbiente.h"

typedef struct eventoclique tEventoClique;

tEventoClique* criaEventoClique(char *caracteresAceitos);

void liberaEventoClique(void* eve);

void processaEventoClique(tAmbiente *amb, void *eve, char c);

int identificaEventoClique(void *eve, char c);

#endif
