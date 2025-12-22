#include "franquia.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_ABREVIACAO_CONFERENCIA 2

struct franquia {
	char *nome;
	char *conferencia;
	int vit_casa, vit_fora;
	int der_casa, der_fora;
	float aproveitamento;
};

tFranquia LeFranquia(void) {
	tFranquia f = calloc(1, sizeof(*f));

	f->nome = malloc((MAX_NOME + 1) * sizeof(*f->nome));
	f->conferencia = malloc((MAX_NOME + 1) * sizeof(*f->conferencia));

	scanf(" %s", f->nome);
	scanf(" %s", f->conferencia);
	getchar();

	return f;
}

void LiberaFranquia(tFranquia f) {
	free(f->nome);
	free(f->conferencia);
	free(f);
}

void ImprimeFranquia(tFranquia f) {
	char conferencia[TAM_ABREVIACAO_CONFERENCIA + 1];
	if (!strcmp(f->conferencia, "LESTE")) {
		strcpy(conferencia, "CL");
	} else if (!strcmp(f->conferencia, "OESTE")) {
		strcpy(conferencia, "CO");
	}

	int qtdVitorias = f->vit_casa + f->vit_fora;
	int qtdDerrotas = f->der_casa + f->der_fora;
	int qtdPartidas = qtdVitorias + qtdDerrotas;
	if (qtdPartidas > 0) {
		f->aproveitamento = 100.0 * qtdVitorias / (qtdVitorias + qtdDerrotas);
	}

	printf(
		"%s [%s] %d %d %.2f %d %d\n",
		f->nome,
		conferencia,
		f->vit_casa + f->vit_fora,
		f->der_casa + f->der_fora,
		f->aproveitamento,
		f->vit_casa,
		f->vit_fora
	);
}

char *GetNomeFranquia(tFranquia f) {
	return f->nome;
}

char *GetConferenciaFranquia(tFranquia f) {
	return f->conferencia;
}

void AdicionaVitoriaCasaFranquia(tFranquia f) {
	f->vit_casa++;
}

void AdicionaVitoriaForaFranquia(tFranquia f) {
	f->vit_fora++;
}

void AdicionaDerrotaCasaFranquia(tFranquia f) {
	f->der_casa++;
}

void AdicionaDerrotaForaFranquia(tFranquia f) {
	f->der_fora++;
}

int GetVitoriaCasaFranquia(tFranquia f) {
	return f->vit_casa;
}

int GetVitoriaForaFranquia(tFranquia f) {
	return f->vit_fora;
}

int GetDerrotaCasaFranquia(tFranquia f) {
	return f->der_casa;
}

int GetDerrotaForaFranquia(tFranquia f) {
	return f->der_fora;
}
