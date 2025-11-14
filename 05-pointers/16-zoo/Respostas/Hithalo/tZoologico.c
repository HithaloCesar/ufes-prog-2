#include "tZoologico.h"
#include <stdio.h>
#include <string.h>

tZoologico CriaZoologico(char *nome, int nRecintos, int capacidade) {
    tZoologico z;

    strcpy(z.nome, nome);
    z.capacidade = capacidade;
    z.nRecintos = nRecintos;
    z.dia = 0;

    for (int i = 0; i < nRecintos; i++) {
        z.recintos[i] = CriaRecinto(capacidade);
    }

    return z;
}

int AdicionaAnimalZoologico(tZoologico *z, tAnimal a) {
    for (int i = 0; i < z->nRecintos; i++) {
        if (AdicionaAnimalRecinto(&z->recintos[i], a)) {
            printf(
                "Animal %s foi adicionado ao recinto %d\n",
                a.nome, i
            );
            return 1;
        }
    }

    return 0;
}

void PassaDiaZoologico(tZoologico *z) {
    for (int i = 0; i < z->nRecintos; i++) {
        PassaDiaRecinto(&z->recintos[i]);
    }

    z->dia++;
}

void FugaRecintoZoologico(tZoologico *z, int idx) {
    if (idx < 0 || idx >= z->nRecintos) {
        printf("Valor invalido\n");
        return;
    }

    FugaRecinto(&z->recintos[idx]);
}

void EncerraZoologico(tZoologico *z) {
    for (int i = 0; i < z->nRecintos; i++) {
        if (!EstaVazioRecinto(&z->recintos[i])) {
            printf("Animais liberados para a finalizacao do programa!!!\n");
            return;
        }
    }

    printf("Programa finalizado com sucesso.\n");
}

int ZoologicoLotado(tZoologico *z) {
    for (int i = 0; i < z->nRecintos; i++) {
        if (!EstaLotadoRecinto(&z->recintos[i])) {
            return 0;
        }
    }

    return 1;
}

char *GetNome(tZoologico *z) {
    return z->nome;
}
