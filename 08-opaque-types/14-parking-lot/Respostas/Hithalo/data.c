#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define HORAS_EM_UM_DIA 24
#define DIAS_EM_UMA_SEMANA 7
#define MESES_EM_UM_ANO 12

typedef enum dia_semana {
    DS_DOMINGO,
    DS_SEGUNDA,
    DS_TERCA,
    DS_QUARTA,
    DS_QUINTA,
    DS_SEXTA,
    DS_SABADO
} DiaSemana;

struct Data {
    int dia, mes, ano;
    int dia_semana;
    float hora;
};

tData *CriaData(void) {
    tData *data = calloc(1, sizeof(*data));

    return data;
}

void DestroiData(tData *data) {
    free(data);
}

void ProcessaDiaMesAno(tData *data, char *str) {
    sscanf(str, "%d/%d/%d", &data->dia, &data->mes, &data->ano);
}

void ProcessaDiaDaSemana(tData *data, char *str) {
    sscanf(str, "%d", &data->dia_semana);
}

void ProcessaHorario(tData *data, char *str) {
    int hora, minuto;
    sscanf(str, "%d:%d", &hora, &minuto);

    data->hora = hora + minuto / 60.0;
}

int VerificaDataValida(tData *data) {
    if (data->mes < 1 || data->mes > MESES_EM_UM_ANO) {
        return 0;
    }

    if (data->dia < 1 || data->dia > NumeroDiasMes(data)) {
        return 0;
    }

    return 1;
}

int VerificaBissexto(tData *data) {
    if (data->ano % 4 == 0 && data->ano != 100) {
        return 1;
    }

    return data->ano % 400 == 0;
}

int NumeroDiasMes(tData *data) {
    if (data->mes == 2) {
        return VerificaBissexto(data) ? 29 : 28;
    }

    if (data->mes <= 7 && data->mes % 2 == 0) {
        return 30;
    }

    if (data->mes >= 8 && data->mes % 2 == 1) {
        return 30;
    }

    return 31;
}

int ComparaDiaMesAno(tData *data1, tData *data2) {
    if (data1->ano != data2->ano) {
        return data1->ano - data2->ano;
    }

    if (data1->mes != data2->mes) {
        return data1->mes - data2->mes;
    }

    return data1->dia - data2->dia;
}

int CalculaDiasAteMes(tData *data) {
    int dias_mes = 0;

    tData *i = CriaData();
    for (i->mes = 1; i->mes < data->mes; i->mes++) {
        dias_mes += NumeroDiasMes(i);
    }
    DestroiData(i);

    return dias_mes;
}

int CalculaDiferencaDias(tData *data1, tData *data2) {
    int diff = ComparaDiaMesAno(data1, data2);

    if (diff == 0) {
        return 0;
    }

    if (diff > 0) {
        tData *aux = data1;
        data1 = data2;
        data2 = aux;
    }

    int diasAteData1 = CalculaDiasAteMes(data1) + data1->dia;
    int diasAteData2 = CalculaDiasAteMes(data2) + data2->dia;

    if (data1->ano == data2->ano) {
        return diasAteData2 - diasAteData1;
    }

    int diasAnosInteiros = 0;
    tData *i = CriaData();
    for (i->ano = data1->ano; i->ano < data2->ano; i->ano++) {
        diasAnosInteiros += VerificaBissexto(i) ? 366 : 365;
    }
    DestroiData(i);

    return diasAnosInteiros + diasAteData2 - diasAteData1;
}

float CalculaHorasEntreDatas(tData *data1, tData *data2) {
    int diff_dia = ComparaDiaMesAno(data1, data2);

    if (diff_dia == 0) {
        float diff_hora = fabs(data1->hora - data2->hora);
        return diff_hora;
    }

    if (diff_dia > 0) {
        tData *aux = data1;
        data1 = data2;
        data2 = aux;
    }

    int diasInteiros = CalculaDiferencaDias(data1, data2);

    return diasInteiros * HORAS_EM_UM_DIA + data2->hora - data1->hora;
}

int DataEhSabadoOuDomingo(tData *data) {
    return data->dia_semana == DS_SABADO || data->dia_semana == DS_DOMINGO;
}

void DataDiaSeguinte(tData *data) {
    data->dia_semana = (data->dia_semana + 1) % DIAS_EM_UMA_SEMANA;
    if (++data->dia > NumeroDiasMes(data)) {
        data->dia = 1;
        if (++data->mes > MESES_EM_UM_ANO) {
            data->mes = 1;
            data->ano++;
        }
    }

    data->hora = 0;
}

void CopiaDiaMesAno(tData *src, tData *tgt) {
    tgt->dia = src->dia;
    tgt->mes = src->mes;
    tgt->ano = src->ano;
    tgt->dia_semana = src->dia_semana;
}
