#include "eleicao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define PRESIDENTE_CHAR 'P'
#define GOVERNADOR_CHAR 'G'

typedef int (*ObtemVoto)(tEleitor*);

static void cadastraCandidato(tEleicao *eleicao, tCandidato *candidato);

static void ProcessaVoto(
    tEleicao *eleicao,
    tEleitor *eleitor,
    ObtemVoto obtemVoto,
    tCandidato **candidatos,
    int totalCandidatos,
    int *votosNulos,
    int *votosBrancos
);

static void ImprimeResultadoCargo(
    char *nomeCargo,
    tCandidato **candidatos,
    int totalCandidatos,
    int totalVotosInvalidos,
    int totalEleitores
);

tEleicao *InicializaEleicao(void) {
    tEleicao *eleicao = calloc(1, sizeof(*eleicao));

    int totalCandidatos;
    scanf("%d", &totalCandidatos);
    getchar();

    eleicao->presidentes = malloc(
        totalCandidatos * sizeof(*eleicao->presidentes)
    );
    eleicao->governadores = malloc(
        totalCandidatos * sizeof(*eleicao->governadores)
    );

    for (int i = 0; i < totalCandidatos; i++) {
        tCandidato *candidato = CriaCandidato();
        LeCandidato(candidato);
        cadastraCandidato(eleicao, candidato);
    }

    return eleicao;
}

void ApagaEleicao(tEleicao *eleicao) {
    for (int i = 0; i < eleicao->totalPresidentes; i++) {
        ApagaCandidato(eleicao->presidentes[i]);
    }
    free(eleicao->presidentes);

    for (int i = 0; i < eleicao->totalGovernadores; i++) {
        ApagaCandidato(eleicao->governadores[i]);
    }
    free(eleicao->governadores);

    for (int i = 0; i < eleicao->totalEleitores; i++) {
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);

    free(eleicao);
}

void RealizaEleicao(tEleicao *eleicao) {
    int totalEleitores;
    scanf("%d", &totalEleitores);
    getchar();

    eleicao->eleitores = malloc(totalEleitores * sizeof(*eleicao->eleitores));

    for (int i = 0; i < totalEleitores; i++) {
        tEleitor *eleitor = CriaEleitor();
        LeEleitor(eleitor);
        eleicao->eleitores[eleicao->totalEleitores++] = eleitor;

        ProcessaVoto(
            eleicao,
            eleitor,
            ObtemVotoPresidente,
            eleicao->presidentes,
            eleicao->totalPresidentes,
            &eleicao->votosNulosPresidente,
            &eleicao->votosBrancosPresidente
        );

        ProcessaVoto(
            eleicao,
            eleitor,
            ObtemVotoGovernador,
            eleicao->governadores,
            eleicao->totalGovernadores,
            &eleicao->votosNulosGovernador,
            &eleicao->votosBrancosGovernador
        );
    }
}

void ImprimeResultadoEleicao(tEleicao *eleicao) {
    for (int i = 0; i < eleicao->totalEleitores - 1; i++) {
        tEleitor *eleitor_i = eleicao->eleitores[i];
        for (int j = i + 1; j < eleicao->totalEleitores; j++) {
            if (EhMesmoEleitor(eleitor_i, eleicao->eleitores[j])) {
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }

    ImprimeResultadoCargo("PRESIDENTE",
        eleicao->presidentes,
        eleicao->totalPresidentes,
        eleicao->votosNulosPresidente + eleicao->votosBrancosPresidente,
        eleicao->totalEleitores
    );

    ImprimeResultadoCargo(
        "GOVERNADOR",
        eleicao->governadores,
        eleicao->totalGovernadores,
        eleicao->votosNulosGovernador + eleicao->votosBrancosGovernador,
        eleicao->totalEleitores);

    printf(
        "- NULOS E BRANCOS: %d, %d\n",
        eleicao->votosNulosPresidente + eleicao->votosNulosGovernador,
        eleicao->votosBrancosPresidente + eleicao->votosBrancosGovernador
    );
}

static void cadastraCandidato(tEleicao *eleicao, tCandidato *candidato) {
    switch (ObtemCargo(candidato)) {
        case PRESIDENTE_CHAR: {
            eleicao->presidentes[eleicao->totalPresidentes++] = candidato;
            break;
        }
        case GOVERNADOR_CHAR: {
            eleicao->governadores[eleicao->totalGovernadores++] = candidato;
            break;
        }
        default: {
            ApagaCandidato(candidato);
            break;
        }
    }
}

static void ProcessaVoto(
    tEleicao *eleicao,
    tEleitor *eleitor,
    ObtemVoto obtemVoto,
    tCandidato **candidatos,
    int totalCandidatos,
    int *votosNulos,
    int *votosBrancos
) {
    int voto = obtemVoto(eleitor);

    if (voto == 0) {
        (*votosBrancos)++;
    } else {
        bool votoNulo = true;
        for (int j = 0; j < totalCandidatos; j++) {
            if (VerificaIdCandidato(candidatos[j], voto)) {
                IncrementaVotoCandidato(candidatos[j]);
                votoNulo = false;
                break;
            }
        }
        if (votoNulo) {
            (*votosNulos)++;
        }
    }
}

static void ImprimeResultadoCargo(
    char *nomeCargo,
    tCandidato **candidatos,
    int totalCandidatos,
    int totalVotosInvalidos,
    int totalEleitores
) {
    printf("- %s ELEITO: ", nomeCargo);

    if (totalCandidatos == 0) {
        printf("SEM CANDIDATOS\n");
        return;
    }

    tCandidato *vencedor = candidatos[0];
    int votosVencedor = ObtemVotos(vencedor);
    bool empate = false;

    for (int i = 1; i < totalCandidatos; i++) {
        int votosCandidato = ObtemVotos(candidatos[i]);

        if (votosCandidato > votosVencedor) {
            vencedor = candidatos[i];
            votosVencedor = votosCandidato;
            empate = false;
        } else if (votosCandidato == votosVencedor) {
            empate = true;
        }
    }

    if (empate) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    } else if (votosVencedor < totalVotosInvalidos) {
        printf("SEM DECISAO\n");
    } else {
        float percentual = CalculaPercentualVotos(vencedor, totalEleitores);
        ImprimeCandidato(vencedor, percentual);
    }
}
