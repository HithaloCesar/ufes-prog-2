#include "data.h"
#include <stdio.h>

void InicializaDataParam(int dia, int mes, int ano, tData *data) {
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    if (data->mes < 1) {
        data->mes = 1;
    } else if (data->mes > 12) {
        data->mes = 12;
    }

    int qtdDiasNoMes = InformaQtdDiasNoMes(data);
    if (data->dia < 1) {
        data->dia = 1;
    } else if (data->dia > qtdDiasNoMes) {
        data->dia = qtdDiasNoMes;
    }
}

void LeData(tData *data) {
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);
}

void ImprimeData(tData *data) {
    printf("'%02d/%02d/%d'", data->dia, data->mes, data->ano);
}

int EhBissexto(tData *data) {
    return (
        (data->ano % 4 == 0 && data->ano % 100 != 0)
        || data->ano % 400 == 0
    );
}

int InformaQtdDiasNoMes(tData *data) {
    if (data->mes == 2) {
        return (EhBissexto(data) ? 29 : 28);
    }

    if (data->mes <= 7) {
        return (data->mes % 2 == 0 ? 30 : 31);
    }

    return (data->mes % 2 == 1 ? 30 : 31);
}

void AvancaParaDiaSeguinte(tData *data) {
    data->dia++;
    if (data->dia > InformaQtdDiasNoMes(data)) {
        data->dia = 1;
        data->mes++;
        if (data->mes > 12) {
            data->mes = 1;
            data->ano++;
        }
    }
}

int EhIgual(tData *data1, tData *data2) {
    return (
        data1->ano == data2->ano
        && data1->mes == data2->mes
        && data1->dia == data2->dia
    );
}
