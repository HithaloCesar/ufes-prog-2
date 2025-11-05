#include "evento.h"
#include <stdio.h>

void cadastrarEvento(Evento *eventos, int *numEventos) {
    if (*numEventos == MAX_EVENTOS) {
        printf("Limite de eventos atingido!\n");
        return;
    }

    scanf(" %[^\n]", eventos[*numEventos].nome);
    scanf("%d", &eventos[*numEventos].dia);
    scanf("%d", &eventos[*numEventos].mes);
    scanf("%d", &eventos[*numEventos].ano);

    (*numEventos)++;

    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento *eventos, int *numEventos) {
    if (*numEventos == 0) {
        printf("Nenhum evento cadastrado.\n");
        return;
    }

    printf("Eventos cadastrados:\n");

    for (int i = 0; i < *numEventos; i++) {
        printf("%d - %s - %d/%d/%d\n",
            i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano
        );
    }
}

void trocarDataEvento(Evento *eventos, int *numEventos) {
    int indiceEvento;
    scanf("%d", &indiceEvento);

    if (indiceEvento >= *numEventos) {
        printf("Indice invalido!\n");
        return;
    }

    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    eventos[indiceEvento].dia = dia;
    eventos[indiceEvento].mes = mes;
    eventos[indiceEvento].ano = ano;

    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(
    Evento *eventos,
    int *indiceA,
    int *indiceB,
    int *numEventos
) {
    if (*indiceA < 0 || *indiceA > *numEventos - 1) {
        printf("Indices invalidos!\n");
        return;
    }
    if (*indiceB < 0 || *indiceB > *numEventos - 1) {
        printf("Indices invalidos!\n");
        return;
    }

    Evento temp = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = temp;

    printf("Eventos trocados com sucesso!\n");
}
