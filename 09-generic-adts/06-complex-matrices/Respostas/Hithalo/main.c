#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrizgenerica.h"
#include "numcomplexo.h"
#include "utils.h"

int main(void) {
    while (true) {
        int linhas, colunas, tipo;
        LeConfiguracao(&linhas, &colunas, &tipo);

        tMatrizGenerica *matriz = CriaLeMatriz(linhas, colunas, tipo);

        int opcaoMatriz = LeOpcaoMatriz();
        switch (opcaoMatriz) {
            case OPCAO_MATRIZ_IMPRIMIR: {
                AcaoImprime(matriz, tipo);
                break;
            }
            case OPCAO_MATRIZ_CONV_COMPLEXO_IMPRIMIR: {
                AcaoConverteImprime(matriz, tipo);
                break;
            }
            case OPCAO_MATRIZ_CONV_COMPLEXO_MULT_TRANSPOSTA: {
                AcaoConverteMultiplicaTranspostaImprime(matriz, tipo);
                break;
            }
        }

        DestroiMatrizGenerica(matriz);

        int opcaoPrograma = LeOpcaoPrograma();
        if (opcaoPrograma == OPCAO_PROGRAMA_FINALIZAR) {
            break;
        }
    }

    return EXIT_SUCCESS;
}
