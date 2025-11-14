#include "tAnimal.h"
#include <stdio.h>
#include <string.h>

tAnimal CriaAnimal(char *nome, int fome) {
    tAnimal animal;
    strcpy(animal.nome, nome);
    animal.fome = fome;

    return animal;
}

void PassaDiaAnimal(tAnimal *a) {
    a->fome++;
}

int AnimalEstaMorto(tAnimal *a) {
    return a->fome >= 10;
}

void ImprimeFugaAnimal(tAnimal *a) {
    printf("Animal %s fugiu!\n", a->nome);
}

void ImprimeMorteAnimal(tAnimal *a) {
    printf("Animal %s morreu de fome.\n", a->nome);
}

char *NomeAnimal(tAnimal *a) {
    return a->nome;
}
