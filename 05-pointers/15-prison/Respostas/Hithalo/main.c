#include <stdlib.h>
#include <stdio.h>
#include "prisao.h"

int main(void) {
    char nome[MAX_TAM_NOME];
    int nCelas, capacidadeCelas;

    scanf("%[^\n]\n", nome);
    scanf("%d %d\n", &nCelas, &capacidadeCelas);

    tPrisao prisao = criaPrisao(nome, nCelas, capacidadeCelas);
    executaPrisao(&prisao);

    return EXIT_SUCCESS;
}
