#include "candidato.h"
#include <stdlib.h>
#include <stdio.h>

tCandidato *CriaCandidato(void) {
    tCandidato *candidato = calloc(1, sizeof(*candidato));

    return candidato;
}

void ApagaCandidato(tCandidato *candidato) {
    free(candidato->nome);
    free(candidato->partido);
    free(candidato);
}

void LeCandidato(tCandidato *candidato) {
    int n = scanf(" %m[^,], %m[^,],", &candidato->nome, &candidato->partido);
    scanf(" %c, %d", &candidato->cargo, &candidato->id);
    getchar();
}

int VerificaIdCandidato(tCandidato *candidato, int id) {
    return candidato->id == id;
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2) {
    return VerificaIdCandidato(candidato1, candidato2->id);
}

char ObtemCargo(tCandidato *candidato) {
    return candidato->cargo;
}

void IncrementaVotoCandidato(tCandidato *candidato) {
    candidato->votos++;
}

int ObtemVotos(tCandidato *candidato) {
    return candidato->votos;
}

float CalculaPercentualVotos(tCandidato *candidato, int totalVotos) {
    return 100.0 * candidato->votos / totalVotos;
}

void ImprimeCandidato (tCandidato *candidato, float percentualVotos) {
    printf(
        "%s (%s), %d voto(s), %.2f%%\n",
        candidato->nome, candidato->partido, candidato->votos, percentualVotos
    );
}
