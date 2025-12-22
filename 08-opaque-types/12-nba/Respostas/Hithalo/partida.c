#include "partida.h"
#include <stdlib.h>
#include <stdio.h>

struct partida {
	char *time1;
	char *time2;
	int pontos1, pontos2;
};

tPartida LePartida(void) {
	tPartida p = calloc(1, sizeof(*p));

	scanf(" %ms @ %ms", &p->time2, &p->time1);

	scanf("%d", &p->pontos2);
	scanf("%d", &p->pontos1);
	getchar();

	return p;
}

void LiberaPartida(tPartida p) {
	free(p->time1);
	free(p->time2);
	free(p);
}

void ImprimePartida(tPartida p) {
	// ???
}

char *GetTime1Partida(tPartida p) {
	return p->time1;
}

char *GetTime2Partida(tPartida p) {
	return p->time2;
}

int GetVencedorPartida(tPartida p) {
	if (p->pontos1 > p->pontos2) {
		return TIME_CASA;
	} else if (p->pontos2 > p->pontos1) {
		return TIME_FORA;
	}

	return -1;
}
