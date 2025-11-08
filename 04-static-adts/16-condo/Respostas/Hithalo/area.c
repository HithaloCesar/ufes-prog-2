#include "area.h"
#include <stdio.h>
#include <string.h>

Area lerArea() {
    Area area;

    scanf(" %[^\n]", area.nome);
    scanf(" %[^\n]", area.id);
    scanf("%d", &area.capacidade);

    return area;
}

void imprimeArea(Area a) {
    printf("Nome: %s\n", a.nome);
    printf("Id: %s\n", a.id);
    printf("Capacidade: %d convidado(s)\n", a.capacidade);
}

int comparaArea(Area a1, Area a2) {
    return !strcmp(a1.id, a2.id);
}

int verificaIdArea(Area a, char *id) {
    return !strcmp(a.id, id);
}

int getCapacidadeArea(Area a) {
    return a.capacidade;
}
