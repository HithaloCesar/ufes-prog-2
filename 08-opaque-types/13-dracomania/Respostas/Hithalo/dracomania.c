#include "dracomania.h"
#include "carta.h"
#include "duelo.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct dracomania {
	tCarta *listacartas;
	int qtdcartas, maxcartas;

	tDuelo *listaduelos;
	int qtdduelos, maxduelos;

	int descartes;
};

tDracomania CriaDracomania(void) {
	tDracomania d = calloc(1, sizeof(*d));

	return d;
}

static tCarta BuscaCartaPorId(tCarta *cartas, int qtdCartas, int id) {
	for (int i = 0; i < qtdCartas; i++) {
		if (GetIdCarta(cartas[i]) == id) {
			return cartas[i];
		}
	}

	return NULL;
}

static int BuscaIndiceCartaPorId(tCarta *cartas, int qtdCartas, int id) {
	for (int i = 0; i < qtdCartas; i++) {
		if (GetIdCarta(cartas[i]) == id) {
			return i;
		}
	}

	return -1;
}

tDracomania RodaDracomania(tDracomania d) {
	bool continuarExecucao = true;
	while (continuarExecucao) {
		char operacao;
		scanf(" %c", &operacao);
		getchar();

		switch (operacao) {
			case CADASTRAR: {
				tCarta c = LeCarta();

				if (!EhCartaValida(c)) {
					LiberaCarta(c);
					d->descartes++;
					break;
				}

				int indiceCartaExistente = BuscaIndiceCartaPorId(
					d->listacartas, d->qtdcartas, GetIdCarta(c)
				);

				if (indiceCartaExistente >= 0) {
					LiberaCarta(d->listacartas[indiceCartaExistente]);
					d->listacartas[indiceCartaExistente] = c;
					break;
				}

				if (d->qtdcartas == d->maxcartas) {
					if (d->maxcartas == 0) {
						d->maxcartas = TAM_LISTA;
					} else {
						d->maxcartas *= 2;
					}
					d->listacartas = realloc(d->listacartas, d->maxcartas * sizeof(*d->listacartas));
				}

				d->listacartas[d->qtdcartas++] = c;

				break;
			}
			case LUTAR: {
				if (d->qtdduelos == d->maxduelos) {
					if (d->maxduelos == 0) {
						d->maxduelos = TAM_LISTA;
					} else {
						d->maxduelos *= 2;
					}
					d->listaduelos = realloc(d->listaduelos, d->maxduelos * sizeof(*d->listaduelos));
				}
				tDuelo duelo = LeDuelo();
				d->listaduelos[d->qtdduelos++] = duelo;

				tCarta c1 = BuscaCartaPorId(d->listacartas, d->qtdcartas, GetC1Duelo(duelo));
				tCarta c2 = BuscaCartaPorId(d->listacartas, d->qtdcartas, GetC2Duelo(duelo));

				RealizaDuelo(duelo, c1, c2);

				break;
			}
			case FINALIZAR: {
				continuarExecucao = false;
				break;
			}
		}
	}

	return d;
}

static tCarta BuscaCartaMaisVitoriosa(tCarta *cartas, int qtdCartas) {
	if (qtdCartas <= 0) {
		return NULL;
	}

	tCarta cartaMaisVitoriosa = cartas[0];
	int numVitMax = GetNumVitCarta(cartaMaisVitoriosa);
	for (int i = 1; i < qtdCartas; i++) {
		int numVit = GetNumVitCarta(cartas[i]);
		if (numVit > numVitMax) {
			cartaMaisVitoriosa = cartas[i];
			numVitMax = numVit;
		}
	}

	return cartaMaisVitoriosa;
}

static tDuelo BuscaDueloMaiorDiff(tDuelo *duelos, int qtdDuelos) {
	if (qtdDuelos <= 0) {
		return NULL;
	}

	tDuelo dueloMaiorDiff = duelos[0];
	int maiorDiff = GetDiferencaDuelo(dueloMaiorDiff);
	for (int i = 1; i < qtdDuelos; i++) {
		int diff = GetDiferencaDuelo(duelos[i]);
		if (diff > maiorDiff) {
			dueloMaiorDiff = duelos[i];
			maiorDiff = diff;
		}
	}

	return dueloMaiorDiff;
}

void ImprimeRelatorioDracomania(tDracomania d) {
	printf("Quantidade de Cartas: %d\n", d->qtdcartas);
	printf("Quantidade de descartadas: %d\n", d->descartes);
	printf("Quantidade de lutas: %d\n", d->qtdduelos);

	if (d->qtdduelos <= 0) {
		return;
	}

	int qtdDesempates = 0;
	for (int i = 0; i < d->qtdduelos; i++) {
		if (GetDesempateDuelo(d->listaduelos[i])) {
			qtdDesempates++;
		}
	}

	tCarta cartaMaisVitoriosa = BuscaCartaMaisVitoriosa(
		d->listacartas, d->qtdcartas
	);

	tDuelo dueloMaiorDiff = BuscaDueloMaiorDiff(d->listaduelos, d->qtdduelos);

	printf("Lutas que foram desempatadas: %d\n", qtdDesempates);
	printf("Carta mais vitoriosa: %s\n", GetNomeCarta(cartaMaisVitoriosa));
	printf("Luta com Maior Diferença: %d\n", GetIdDuelo(dueloMaiorDiff));
}

void LiberaDracomania(tDracomania d) {
	for (int i = 0; i < d->qtdcartas; i++) {
		LiberaCarta(d->listacartas[i]);
	}

	for (int i = 0; i < d->qtdduelos; i++) {
		LiberaDuelo(d->listaduelos[i]);
	}

	free(d->listacartas);
	free(d->listaduelos);
	free(d);
}
