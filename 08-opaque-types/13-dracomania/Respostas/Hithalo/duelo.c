#include "duelo.h"
#include <stdlib.h>
#include <stdio.h>

struct duelo {
	int id;
	int c1, c2;
	char atributo;
	bool desempate;
	int vencedor;
	int diferenca;
};

tDuelo LeDuelo(void) {
	tDuelo d = calloc(1, sizeof(*d));

	scanf("%d", &d->id);
	scanf("%d %d %c", &d->c1, &d->c2, &d->atributo);
	getchar();

	return d;
}

void LiberaDuelo(tDuelo d) {
	free(d);
}

void ImprimeDuelo(tDuelo d) {
	// ???
}

void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2) {
	switch (d->atributo) {
		case MAGIA: {
			d->diferenca = GetMagiaCarta(c1) - GetMagiaCarta(c2);
			break;
		}
		case FORCA: {
			d->diferenca = GetAtaqueCarta(c1) - GetAtaqueCarta(c2);
			break;
		}
		case FOGO: {
			d->diferenca = GetFogoCarta(c1) - GetFogoCarta(c2);
			break;
		}
	}

	int idC1 = GetIdCarta(c1);
	int idC2 = GetIdCarta(c2);

	if (d->diferenca > 0) {
		d->vencedor = idC1;
		AdicionaVitoriaCarta(c1);
	} else if (d->diferenca < 0) {
		d->vencedor = idC2;
		AdicionaVitoriaCarta(c2);
	} else {
		int diferencaId = ComparaIdCarta(c1, c2);
		if (diferencaId > 0) {
			d->vencedor = idC1;
		} else if (diferencaId < 0) {
			d->vencedor = idC2;
		}
		d->desempate = true;
	}
}

int GetC1Duelo(tDuelo d) {
	return d->c1;
}

int GetC2Duelo(tDuelo d) {
	return d->c2;
}

bool GetDesempateDuelo(tDuelo d) {
	return d->desempate;
}

int GetDiferencaDuelo(tDuelo d) {
	return d->diferenca;
}

int GetIdDuelo(tDuelo d) {
	return d->id;
}
