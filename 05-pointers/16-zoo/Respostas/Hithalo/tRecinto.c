#include "tRecinto.h"
#include <stdio.h>

tRecinto CriaRecinto(int capacidade) {
    tRecinto r;
    r.capacidade = capacidade;
    r.qtd = 0;

    return r;
}

int AdicionaAnimalRecinto(tRecinto *r, tAnimal a) {
    if (EstaLotadoRecinto(r)) {
        return 0;
    }

    r->animais[r->qtd++] = a;

    return 1;
}

void PassaDiaRecinto(tRecinto *r) {
    for (int i = 0; i < r->qtd; i++) {
        PassaDiaAnimal(&r->animais[i]);
        if (AnimalEstaMorto(&r->animais[i])) {
            ImprimeMorteAnimal(&r->animais[i]);

            for (int j = i; j < r->qtd - 1; j++) {
                r->animais[j] = r->animais[j + 1];
            }

            i--;
            r->qtd--;
        }
    }
}

void FugaRecinto(tRecinto *r) {
    for (int i = 0; i < r->qtd; i++) {
        ImprimeFugaAnimal(&r->animais[i]);
    }

    r->qtd = 0;
}

int EstaLotadoRecinto(tRecinto *r) {
    return r->qtd >= r->capacidade;
}

int EstaVazioRecinto(tRecinto *r) {
    return r->qtd == 0;
}
