#include "data.h"
#include <stdlib.h>
#include <stdio.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

Data *criaData(int dia, int mes, int ano) {
    Data *data = malloc(sizeof(*data));
    if (data == NULL) {
        return NULL;
    }

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    return data;
}

Data *lerData() {
    int dia, mes, ano;
    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    return criaData(dia, mes, ano);
}

int diferencaAnoData(Data *inicial, Data *atual) {
    int ajuste = 0;
    if (atual->mes < inicial->mes || (atual->mes == inicial->mes && atual->dia < inicial->dia)) {
        ajuste = 1;
    }

    return atual->ano - inicial->ano - ajuste;
}

void imprimeData(Data *d) {
    printf("%d/%d/%d", d->dia, d->mes, d->ano);
}

void liberaData(Data *d) {
    free(d);
}
