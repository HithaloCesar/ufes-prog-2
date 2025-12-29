#ifndef UTILS_H
#define UTILS_H

#include "matrizgenerica.h"

enum opcao_matriz {
    OPCAO_MATRIZ_IMPRIMIR = 1,
    OPCAO_MATRIZ_CONV_COMPLEXO_IMPRIMIR,
    OPCAO_MATRIZ_CONV_COMPLEXO_MULT_TRANSPOSTA
};

enum opcao_programa {
    OPCAO_PROGRAMA_CONTINUAR = 1,
    OPCAO_PROGRAMA_FINALIZAR
};

enum tipo {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_DOUBLE,
    TIPO_CHAR,
    TIPO_COMPLEXO
};

void LeConfiguracao(int *linhas, int *colunas, int *tipo);
int LeOpcaoMatriz(void);
int LeOpcaoPrograma(void);

tMatrizGenerica *CriaLeMatriz(int linhas, int colunas, int tipo);

void AcaoImprime(tMatrizGenerica *m, int tipo);
void AcaoConverteImprime(tMatrizGenerica *m, int tipo);
void AcaoConverteMultiplicaTranspostaImprime(tMatrizGenerica *m, int tipo);

#endif
