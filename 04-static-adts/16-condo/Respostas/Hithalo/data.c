#include "data.h"
#include <stdio.h>

Data lerData() {
    Data d;
    scanf("%d/%d/%d\n", &d.dia, &d.mes, &d.ano);

    return d;
}

void imprimeData(Data d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

int comparaData(Data d1, Data d2) {
    return (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia);
}

int calcularDiffAnosData(Data inicio, Data fim) {
    int anosCompletos = fim.ano - inicio.ano;

    if (fim.mes < inicio.mes
        || (fim.mes == inicio.mes && fim.dia < inicio.dia)) {
        anosCompletos--;
    }

    return anosCompletos;
}
