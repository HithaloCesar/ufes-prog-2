#include "nba.h"
#include "franquia.h"
#include "partida.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct nba {
	tFranquia *listafranquias;
	int qtdfranquias, maxfranquias;

	tPartida *listapartidas;
	int qtdpartidas, maxpartidas;
};

typedef struct dados_relatorio {
	int qtdVitoriasLeste;
	int qtdDerrotasLeste;
	float aproveitamentoLeste;
	int qtdVitoriasOeste;
	int qtdDerrotasOeste;
	float aproveitamentoOeste;
} DadosRelatorio;

static void CadastraFranquia(tNBA nba);
static tFranquia BuscaFranquia(
	tFranquia *franquias,
	int qtdFranquias,
	char *nome
);
static void CadastraPartida(tNBA nba);
static void ProcessaRelatorio(tNBA nba, DadosRelatorio *d);

tNBA CriaNBA(void) {
	tNBA nba = calloc(1, sizeof(*nba));

	return nba;
}

tNBA RodaNBA(tNBA nba) {
	bool continuarexecucao = true;
	while (continuarexecucao) {
		char operacao;
		scanf(" %c", &operacao);
		getchar();

		switch (operacao) {
			case CAD_FRANQUIA: {
				CadastraFranquia(nba);
				break;
			}
			case CAD_PARTIDA: {
				CadastraPartida(nba);
				break;
			}
			case ENCERRAR: {
				continuarexecucao = false;
				break;
			}
		}
	}

	return nba;
}

void ImprimeRelatorioNBA(tNBA nba) {
	DadosRelatorio d = {0};
	ProcessaRelatorio(nba, &d);

	for (int i = 0; i < nba->qtdfranquias; i++) {
		ImprimeFranquia(nba->listafranquias[i]);
	}

	printf(
		"LESTE %d %d %.2f\n",
		d.qtdVitoriasLeste,
		d.qtdDerrotasLeste,
		d.aproveitamentoLeste
	);
	printf(
		"OESTE %d %d %.2f\n",
		d.qtdVitoriasOeste,
		d.qtdDerrotasOeste,
		d.aproveitamentoOeste
	);
}

void LiberaNBA(tNBA nba) {
	for (int i = 0; i < nba->qtdfranquias; i++) {
		LiberaFranquia(nba->listafranquias[i]);
	}
	for (int i = 0; i < nba->qtdpartidas; i++) {
		LiberaPartida(nba->listapartidas[i]);
	}
	free(nba->listafranquias);
	free(nba->listapartidas);
	free(nba);
}

static void CadastraFranquia(tNBA nba) {
	tFranquia f = LeFranquia();

	if (nba->qtdfranquias == nba->maxfranquias) {
		if (nba->maxfranquias == 0) {
			nba->maxfranquias = MAX_FR;
		} else {
			nba->maxfranquias *= 2;
		}
		nba->listafranquias = realloc(
			nba->listafranquias,
			nba->maxfranquias * sizeof(nba->listafranquias)
		);
	}

	nba->listafranquias[nba->qtdfranquias++] = f;
}

static tFranquia BuscaFranquia(
	tFranquia *franquias,
	int qtdFranquias,
	char *nome
) {
	for (int i = 0; i < qtdFranquias; i++) {
		if (!strcmp(GetNomeFranquia(franquias[i]), nome)) {
			return franquias[i];
		}
	}

	return NULL;
}

static void CadastraPartida(tNBA nba) {
	tPartida p = LePartida();

	if (nba->qtdpartidas == nba->maxpartidas) {
		if (nba->maxpartidas == 0) {
			nba->maxpartidas = MAX_PT;
		} else {
			nba->maxpartidas *= 2;
		}
		nba->listapartidas = realloc(
			nba->listapartidas,
			nba->maxpartidas * sizeof(nba->listapartidas)
		);
	}

	tFranquia timeCasa = BuscaFranquia(
		nba->listafranquias, nba->qtdfranquias, GetTime1Partida(p)
	);
	tFranquia timeFora = BuscaFranquia(
		nba->listafranquias, nba->qtdfranquias, GetTime2Partida(p)
	);

	int vencedorid = GetVencedorPartida(p);
	if (vencedorid == TIME_CASA) {
		AdicionaVitoriaCasaFranquia(timeCasa);
		AdicionaDerrotaForaFranquia(timeFora);
	} else if (vencedorid == TIME_FORA) {
		AdicionaVitoriaForaFranquia(timeFora);
		AdicionaDerrotaCasaFranquia(timeCasa);
	}

	nba->listapartidas[nba->qtdpartidas++] = p;
}

static void ProcessaRelatorio(tNBA nba, DadosRelatorio *d) {
	for (int i = 0; i < nba->qtdfranquias; i++) {
		tFranquia f = nba->listafranquias[i];
		int qtdVit = GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f);
		int qtdDer = GetDerrotaCasaFranquia(f) + GetDerrotaForaFranquia(f);
		if (!strcmp(GetConferenciaFranquia(f), "LESTE")) {
			d->qtdVitoriasLeste += qtdVit;
			d->qtdDerrotasLeste += qtdDer;
		} else if (!strcmp(GetConferenciaFranquia(f), "OESTE")) {
			d->qtdVitoriasOeste += qtdVit;
			d->qtdDerrotasOeste += qtdDer;
		}
	}

	int qtdPartidasLeste = d->qtdVitoriasLeste + d->qtdDerrotasLeste;
	int qtdPartidasOeste = d->qtdVitoriasOeste + d->qtdDerrotasOeste;

	if (qtdPartidasLeste > 0) {
		d->aproveitamentoLeste = 100.0 * d->qtdVitoriasLeste / qtdPartidasLeste;
	}
	if (qtdPartidasOeste > 0) {
		d->aproveitamentoOeste = 100.0 * d->qtdVitoriasOeste / qtdPartidasOeste;
	}
}
