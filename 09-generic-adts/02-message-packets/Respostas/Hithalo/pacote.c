#include "pacote.h"
#include <stdlib.h>
#include <stdio.h>

struct pacote {
    void *elementos;
    int qtdElem;
    int somaDeVerificacao;
    Type tipo;
};

tPacote *CriaPacote(Type type, int numElem) {
    tPacote *pac = calloc(1, sizeof(*pac));

    pac->tipo = type;
    pac->qtdElem = numElem;

    switch (pac->tipo) {
        case CHAR: {
            pac->elementos = calloc(pac->qtdElem, sizeof(char));
            break;
        }
        case INT: {
            pac->elementos = calloc(pac->qtdElem, sizeof(int));
            break;
        }
    }

    return pac;
}

void DestroiPacote(tPacote *pac) {
    free(pac->elementos);
    free(pac);
}

void LePacote(tPacote *pac) {
    getchar();
    for (int i = 0; i < pac->qtdElem; i++) {
        switch (pac->tipo) {
            case CHAR: {
                scanf("%c", &((char *)pac->elementos)[i]);
                break;
            }
            case INT: {
                scanf("%d", &((int *)pac->elementos)[i]);
                break;
            }
        }
    }
    getchar();
}

void ImprimePacote(tPacote *pac) {
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->somaDeVerificacao);

    char *sep = "";
    for (int i = 0; i < pac->qtdElem; i++) {
        switch (pac->tipo) {
            case CHAR: {
                printf("%c", ((char *)pac->elementos)[i]);
                break;
            }
            case INT: {
                printf("%s%d", sep, ((int *)pac->elementos)[i]);
                break;
            }
        }
        sep = " ";
    }

    putchar('\n');
}

void CalculaSomaVerificacaoPacote(tPacote *pac) {
    pac->somaDeVerificacao = 0;
    for (int i = 0; i < pac->qtdElem; i++) {
        switch (pac->tipo) {
            case CHAR: {
                pac->somaDeVerificacao += ((char *)pac->elementos)[i];
                break;
            }
            case INT: {
                pac->somaDeVerificacao += ((int *)pac->elementos)[i];
                break;
            }
        }
    }
}
