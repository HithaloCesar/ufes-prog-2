#include "circulo.h"
#include <stdlib.h>

struct circulo {
	tPonto centro;
	float r;
};

tCirculo Circulo_Cria(float x, float y, float r) {
	tCirculo c = malloc(sizeof(*c));

	c->centro = Pto_Cria(x, y);
	c->r = r;

	return c;
}

void Circulo_Apaga(tCirculo c) {
	Pto_Apaga(c->centro);
	free(c);
}

tPonto Circulo_Acessa_Centro(tCirculo c) {
	return c->centro;
}

float Circulo_Acessa_Raio(tCirculo c) {
	return c->r;
}

void Circulo_Atribui_Centro(tCirculo c, tPonto p) {
	c->centro = p;
}

void Circulo_Atribui_Raio(tCirculo c, float r) {
	c->r = r;
}

int Circulo_Interior(tCirculo c, tPonto p) {
	return Pto_Distancia(c->centro, p) <= c->r;
}
