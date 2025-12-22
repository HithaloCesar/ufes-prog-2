#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrix_utils.h"

typedef enum {
    OPCAO_ADICAO = 1,
    OPCAO_SUBTRACAO,
    OPCAO_MULTIPLICACAO,
    OPCAO_MULTIPLICACAO_ESCALAR,
    OPCAO_TRANSPOSICAO,
    OPCAO_ENCERRAR
} tOpcao;

static void ImprimirMenu(void);
static void OpcaoMatrixAdd(tMatrix *m1, tMatrix *m2);
static void OpcaoMatrixSub(tMatrix *m1, tMatrix *m2);
static void OpcaoMatrixMultiply(tMatrix *m1, tMatrix *m2);
static void OpcaoMatrixMultiplyScalar(tMatrix **m1, tMatrix **m2);
static void OpcaoMatrixTransposition(tMatrix *m1, tMatrix *m2);

int main(void) {
    int rows1, cols1;
    scanf("%d %d", &rows1, &cols1);
    getchar();

    tMatrix *matrix1 = MatrixCreate(rows1, cols1);
    MatrixRead(matrix1);

    int rows2, cols2;
    scanf("%d %d", &rows2, &cols2);
    getchar();

    tMatrix *matrix2 = MatrixCreate(rows2, cols2);
    MatrixRead(matrix2);

    bool continuarExecucao = true;
    while (continuarExecucao) {
        ImprimirMenu();

        int opcao;
        scanf("%d", &opcao);
        getchar();

        putchar('\n');

        switch(opcao) {
            case OPCAO_ADICAO: {
                OpcaoMatrixAdd(matrix1, matrix2);
                break;
            }
            case OPCAO_SUBTRACAO: {
                OpcaoMatrixSub(matrix1, matrix2);
                break;
            }
            case OPCAO_MULTIPLICACAO: {
                OpcaoMatrixMultiply(matrix1, matrix2);
                break;
            }
            case OPCAO_MULTIPLICACAO_ESCALAR: {
                OpcaoMatrixMultiplyScalar(&matrix1, &matrix2);
                break;
            }
            case OPCAO_TRANSPOSICAO: {
                OpcaoMatrixTransposition(matrix1, matrix2);
                break;
            }
            case OPCAO_ENCERRAR: {
                continuarExecucao = false;
                break;
            }
        }
    }

    MatrixFree(matrix1);
    MatrixFree(matrix2);

    return EXIT_SUCCESS;
}

static void ImprimirMenu(void) {
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
}

static void OpcaoMatrixAdd(tMatrix *m1, tMatrix *m2) {
    if (!PossibleMatrixSum(m1, m2)) {
        printf("Erro: as dimensoes da matriz nao correspondem\n");
        return;
    }
    tMatrix *result = MatrixAdd(m1, m2);
    MatrixPrint(result);
    MatrixFree(result);
}

static void OpcaoMatrixSub(tMatrix *m1, tMatrix *m2) {
    if (!PossibleMatrixSub(m1, m2)) {
        printf("Erro: as dimensoes da matriz nao correspondem\n");
        return;
    }
    tMatrix *result = MatrixSub(m1, m2);
    MatrixPrint(result);
    MatrixFree(result);
}

static void OpcaoMatrixMultiply(tMatrix *m1, tMatrix *m2) {
    if (!PossibleMatrixMultiply(m1, m2)) {
        printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        return;
    }
    tMatrix *result = MatrixMultiply(m1, m2);
    MatrixPrint(result);
    MatrixFree(result);
}

static void OpcaoMatrixMultiplyScalar(tMatrix **m1, tMatrix **m2) {
    int scalar, mId;
    scanf("%d %d", &scalar, &mId);
    getchar();

    switch (mId) {
        case 1: {
            tMatrix *result = MatrixMultiplyByScalar(*m1, scalar);
            MatrixFree(*m1);
            *m1 = result;
            MatrixPrint(*m1);
            break;
        }
        case 2: {
            tMatrix *result = MatrixMultiplyByScalar(*m2, scalar);
            MatrixFree(*m2);
            *m2 = result;
            MatrixPrint(*m2);
            break;
        }
    }
}

static void OpcaoMatrixTransposition(tMatrix *m1, tMatrix *m2) {
    tMatrix *result = TransposeMatrix(m1);
    MatrixPrint(result);
    MatrixFree(result);

    result = TransposeMatrix(m2);
    MatrixPrint(result);
    MatrixFree(result);
}
