#include "numcomplexo.h"
#include <stdlib.h>
#include <stdio.h>

struct complexo {
    float real, imag;
};

tNumComplexo *CriaNumComplexo(float real, float imag) {
    tNumComplexo *cplx = calloc(1, sizeof(*cplx));

    cplx->real = real;
    cplx->imag = imag;

    return cplx;
}

float PegaParteImagComplexo(tNumComplexo *cplx) {
    return cplx->imag;
}

float PegaParteRealComplexo(tNumComplexo *cplx) {
    return cplx->real;
}

void ImprimeNumeroComplexo(tNumComplexo *cplx) {
    printf("%.2f + i%.2f", cplx->real, cplx->imag);
}

void DestroiNumeroComplexo(tNumComplexo *cplx) {
    free(cplx);
}

int RetornaNumBytesComplexo(void) {
    return sizeof(struct complexo);
}

tNumComplexo *SomaComplexos(tNumComplexo *n1, tNumComplexo *n2) {
    float n1Real = PegaParteRealComplexo(n1);
    float n1Imag = PegaParteImagComplexo(n1);

    float n2Real = PegaParteRealComplexo(n2);
    float n2Imag = PegaParteImagComplexo(n2);

    return CriaNumComplexo(n1Real + n2Real, n1Imag + n2Imag);
}

tNumComplexo *MultComplexos(tNumComplexo *n1, tNumComplexo *n2) {
    float real = n1->real * n2->real - n1->imag * n2->imag;
    float imag = n1->real * n2->imag + n1->imag * n2->real;

    return CriaNumComplexo(real, imag);
}
