#include <stdlib.h>
#include <stdio.h>
#include "agencia.h"

int main(void) {
    tAgencia *agencia = CriaAgencia();
    puts("--- Agencia Bancaria ---");

    LeOperacoes(agencia);
    ImprimeOperacoesSuspeitas(agencia);
    ImprimeDoisCorrentistasComMaiorSaldo(agencia);
    ImprimeSaldoTotal(agencia);
    putchar('\n');

    DestroiAgencia(agencia);

    return EXIT_SUCCESS;
}
