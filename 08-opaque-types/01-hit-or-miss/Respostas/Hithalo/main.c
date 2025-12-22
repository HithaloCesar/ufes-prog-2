#include <stdlib.h>
#include <stdio.h>
#include "circulo.h"

int main(void) {
    float centro_x, centro_y, raio;
    scanf("%f %f %f", &centro_x, &centro_y, &raio);
    getchar();
    tCirculo circulo = Circulo_Cria(centro_x, centro_y, raio);

    float x, y;
    scanf("%f %f", &x, &y);
    getchar();
    tPonto ponto = Pto_Cria(x, y);

    printf("%d\n", Circulo_Interior(circulo, ponto));

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return EXIT_SUCCESS;
}
