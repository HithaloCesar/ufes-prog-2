#include "prisao.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

tPrisao criaPrisao(char *nome, int nCelas, int capacidadeCelas) {
    tPrisao p;

    strcpy(p.nome, nome);
    p.nCelas = nCelas;
    p.capacidadeCelas = capacidadeCelas;
    p.dia = 0;

    for (int i = 0; i < nCelas; i++) {
        p.celas[i] = criaCela(capacidadeCelas);
    }

    return p;
}

void executaPrisao(tPrisao *prisao) {
    bool executarPrograma = true;
    while (executarPrograma) {
        imprimeDiaEMenuPrisao(prisao);

        char opcao;
        scanf(" %c", &opcao);

        switch(opcao) {
            case 'I': {
                inserePrisioneiroPrisao(prisao);
                int lotacaoMaxima = prisao->capacidadeCelas * prisao->nCelas;
                if (obtemNumeroPrisioneirosPrisao(prisao) >= lotacaoMaxima) {
                    rebeliaoGeralPrisao(prisao);
                    finalizaPrograma(prisao);
                    executarPrograma = false;
                }
                break;
            }
            case 'P': {
                passaDiaPrisao(prisao);
                break;
            }
            case 'F': {
                registraFugaCelaPrisao(prisao);
                break;
            }
            case 'E': {
                finalizaPrograma(prisao);
                executarPrograma = false;
                break;
            }
            default: {
                break;
            }
        }
    }
}

void imprimeDiaEMenuPrisao(tPrisao *prisao) {
    printf("Dia %d na prisao de %s\n", prisao->dia, prisao->nome);
    printf("Menu:\n");
    printf(" I - Inserir detento\n");
    printf(" P - Passar o dia\n");
    printf(" F - Registrar fuga de cela\n");
    printf(" E - Encerrar programa\n");
}

void inserePrisioneiroPrisao(tPrisao *prisao) {
    int pena;
    char nome[MAX_TAM_NOME];

    printf("Informe a pena e o nome do prisioneiro:\n");
    scanf("%d %[^\n]", &pena, nome);

    if (pena <= 0) {
        printf("Valor invalido\n");
        return;
    }

    tPrisioneiro p = criaPrisioneiro(nome, pena);

    for (int i = 0; i < prisao->nCelas; i++) {
        if (possuiVagaCela(&prisao->celas[i])) {
            inserePrisioneiroCela(&prisao->celas[i], p);
            printf("Detento %s foi inserido na cela %d\n", p.nome, i);
            break;
        }
    }
}

void passaDiaPrisao(tPrisao *prisao) {
    for (int i = 0; i < prisao->nCelas; i++) {
        passaDiaCela(&prisao->celas[i]);
    }
    prisao->dia++;
}

void registraFugaCelaPrisao(tPrisao *prisao) {
    int celaIndice;

    printf("Informe a cela em qual ocorreu a fuga:\n");
    scanf("%d", &celaIndice);

    if (celaIndice < 0 || celaIndice >= prisao->nCelas) {
        printf("Valor invalido\n");
        return;
    }

    fogePrisioneirosCela(&prisao->celas[celaIndice]);
}

void finalizaPrograma(tPrisao *prisao) {
    if (obtemNumeroPrisioneirosPrisao(prisao) > 0) {
        printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
    } else {
        printf("Fim do programa.\n");
    }
}

int obtemNumeroPrisioneirosPrisao(tPrisao *prisao) {
    int totalPresos = 0;
    for (int i = 0; i < prisao->nCelas; i++) {
        totalPresos += obtemNumeroPrisioneirosCela(&prisao->celas[i]);
    }

    return totalPresos;
}

void rebeliaoGeralPrisao(tPrisao *prisao) {
    printf("REBELIAO GERAL\n");
    for (int i = 0; i < prisao->nCelas; i++) {
        fogePrisioneirosCela(&prisao->celas[i]);
    }
}
