#include "carta.h"
#include <stdlib.h>
#include <stdio.h>

tCarta LeCarta(void) {
	tCarta c = calloc(1, sizeof(*c));
	c->nome = calloc(MAX_NOME + 1, sizeof(*c->nome));

	scanf("%d", &c->id);
	scanf(" %[^\n]", c->nome);
	scanf("%d %d %d", &c->magia, &c->ataque, &c->fogo);
	getchar();

	return c;
}

void LiberaCarta(tCarta c) {
	free(c->nome);
	free(c);
}

void ImprimeCarta(tCarta c) {
	// ???
}

int GetIdCarta(tCarta c) {
	return c->id;
}

char *GetNomeCarta(tCarta c) {
	return c->nome;
}

int GetNumVitCarta(tCarta c) {
	return c->num_vit;
}

int GetMagiaCarta(tCarta c) {
	return c->magia;
}

int GetAtaqueCarta(tCarta c) {
	return c->ataque;
}

int GetFogoCarta(tCarta c) {
	return c->fogo;
}

bool EhCartaValida(tCarta c) {
	if (c->magia > 30 || c->ataque > 30 || c->fogo > 30) {
		return false;
	}

	if (c->magia + c->ataque + c->fogo > 80) {
		return false;
	}

	return true;
}

bool EhMesmoIdCarta(tCarta c1, tCarta c2) {
	return c1->id == c2->id;
}

int ComparaIdCarta(tCarta c1, tCarta c2) {
	return c1->id - c2->id;
}

int ComparaMagiaCarta(tCarta c1, tCarta c2) {
	return c1->magia - c2->magia;
}

int ComparaAtaqueCarta(tCarta c1, tCarta c2) {
	return c1->ataque - c2->ataque;
}

int ComparaFogoCarta(tCarta c1, tCarta c2) {
	return c1->fogo - c2->fogo;
}

int AdicionaVitoriaCarta(tCarta c) {
	c->num_vit++;

	return c->num_vit;
}
