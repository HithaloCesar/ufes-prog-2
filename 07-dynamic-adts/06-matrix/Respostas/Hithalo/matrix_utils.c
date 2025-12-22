#include "matrix_utils.h"
#include <stdlib.h>
#include <stdio.h>

typedef int (*tIntOp)(int, int);

static void LimpaBuffer(void);
static int MatrixSameDimensions(tMatrix *matrix1, tMatrix *matrix2);
static int IntAdicao(int a, int b);
static int IntSubtracao(int a, int b);
static tMatrix *ElementWiseMatrixOperation(
    tMatrix *m1,
    tMatrix *m2,
    tIntOp operation
);

tMatrix *MatrixCreate(int rows, int cols) {
    tMatrix *matrix = calloc(1, sizeof(*matrix));

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = calloc(rows, sizeof(*matrix->data));

    for (int i = 0; i < matrix->rows; i++) {
        matrix->data[i] = calloc(cols, sizeof(*matrix->data[i]));
    }

    return matrix;
}

void MatrixFree(tMatrix *matrix) {
    if (!matrix) {
        return;
    }

    if (!matrix->data) {
        free (matrix);
        return;
    }

    for (int i = 0; i < matrix->rows; i++) {
        if (matrix->data[i]) {
            free(matrix->data[i]);
        }
    }

    free(matrix->data);
    free(matrix);
}

void MatrixRead(tMatrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            scanf("%d", &matrix->data[i][j]) != 1;
        }
        getchar();
    }
}

void MatrixPrint(tMatrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        char *separator = "";
        putchar('|');
        for (int j = 0; j < matrix->cols; j++) {
            printf("%s%d", separator, matrix->data[i][j]);
            separator = " ";
        }
        puts("|");
    }
    putchar('\n');
}

int PossibleMatrixSum(tMatrix *matrix1, tMatrix *matrix2) {
    return MatrixSameDimensions(matrix1, matrix2);
}

int PossibleMatrixSub(tMatrix *matrix1, tMatrix *matrix2) {
    return MatrixSameDimensions(matrix1, matrix2);
}

int PossibleMatrixMultiply(tMatrix *matrix1, tMatrix *matrix2) {
    return matrix1->cols == matrix2->rows;
}

tMatrix *MatrixAdd(tMatrix *matrix1, tMatrix *matrix2) {
    return ElementWiseMatrixOperation(matrix1, matrix2, IntAdicao);
}

tMatrix *MatrixSub(tMatrix *matrix1, tMatrix *matrix2) {
    return ElementWiseMatrixOperation(matrix1, matrix2, IntSubtracao);
}

tMatrix *MatrixMultiply(tMatrix *matrix1, tMatrix *matrix2) {
    tMatrix *result = MatrixCreate(matrix1->rows, matrix2->cols);

    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }

    return result;
}

tMatrix *TransposeMatrix(tMatrix *matrix) {
    tMatrix *result = MatrixCreate(matrix->cols, matrix->rows);

    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = matrix->data[j][i];
        }
    }

    return result;
}

tMatrix *MatrixMultiplyByScalar(tMatrix *matrix, int scalar) {
    tMatrix *result = MatrixCreate(matrix->rows, matrix->cols);

    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            result->data[i][j] = matrix->data[i][j] * scalar;
        }
    }

    return result;
}

static int MatrixSameDimensions(tMatrix *matrix1, tMatrix *matrix2) {
    return matrix1->rows == matrix2->rows && matrix1->cols == matrix2->cols;
}

static int IntAdicao(int a, int b) {
    return a + b;
}

static int IntSubtracao(int a, int b) {
    return a - b;
}

static tMatrix *ElementWiseMatrixOperation(
    tMatrix *m1,
    tMatrix *m2,
    tIntOp operation
) {
    tMatrix *result = MatrixCreate(m1->rows, m1->cols);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->data[i][j] = operation(m1->data[i][j], m2->data[i][j]);
        }
    }

    return result;
}
