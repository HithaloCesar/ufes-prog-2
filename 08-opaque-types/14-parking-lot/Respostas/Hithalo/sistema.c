#define _GNU_SOURCE

#include "sistema.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_TOKENS 5
#define HORAS_EM_UM_DIA 24
#define CUSTO_HORA_DIA_UTIL 1
#define CUSTO_HORA_FINAL_DE_SEMANA 2

struct Sistema {
    float faturamento;
};

static void CalculaHoras(
    tData *dataEntrada,
    tData *dataSaida,
    float *horasDiasUteis,
    float *horasFinaisDeSemana
);

tSistema *CriaSistema(void) {
    tSistema *sys = calloc(1, sizeof(*sys));

    return sys;
}

void DestroiSistema(tSistema *sys) {
    free(sys);
}

void LeSistema(tSistema *sys) {
    char *str;
    while (scanf(" %m[^\n]", &str) == 1) {
        char *delim = ";";
        char *ptr;

        char *strings[MAX_TOKENS];

        char *token = strtok_r(str, delim, &ptr);
        for (int i = 0; token != NULL; i++) {
            strings[i] = calloc(strlen(token) + 1, sizeof(*strings[i]));
            strcpy(strings[i], token);
            token = strtok_r(NULL, delim, &ptr);
        }

        tData *dataEntrada = CriaData();
        ProcessaDiaDaSemana(dataEntrada, strings[0]);
        ProcessaDiaMesAno(dataEntrada, strings[1]);
        ProcessaHorario(dataEntrada, strings[2]);

        tData *dataSaida = CriaData();
        ProcessaDiaMesAno(dataSaida, strings[3]);
        ProcessaHorario(dataSaida, strings[4]);

        float preco = CalculaPrecoTiquete(sys, dataEntrada, dataSaida);
        printf("O tiquete processado tem valor: %.2f reais\n", preco);

        sys->faturamento += preco;

        free(dataEntrada);
        free(dataSaida);
        free(str);
        for (int i = 0; i < MAX_TOKENS; i++) {
            free(strings[i]);
        }
    }
}

float CalculaPrecoTiquete(tSistema *sys, tData *dataEntrada, tData *dataSaida) {
    float preco = 0;

    if (ComparaDiaMesAno(dataEntrada, dataSaida) == 0) {
        float horas = CalculaHorasEntreDatas(dataEntrada, dataSaida);

        if (horas < 0.25) {
            return 0;
        }

        horas = ceil(horas);
        preco += DataEhSabadoOuDomingo(dataEntrada) ? horas * 2 : horas;

        return preco;
    }

    float hDiasUteis = 0;
    float hFinaisDeSemana = 0;
    CalculaHoras(dataEntrada, dataSaida, &hDiasUteis, &hFinaisDeSemana);

    if (hDiasUteis + hFinaisDeSemana < 0.25) {
        return 0;
    }

    preco += ceil(hDiasUteis) * CUSTO_HORA_DIA_UTIL;
    preco += ceil(hFinaisDeSemana) * CUSTO_HORA_FINAL_DE_SEMANA;

    return preco;
}

void ImprimeFaturamentoSistema(tSistema *sys) {
    printf("O sistema faturou: %.2f reais\n", sys->faturamento);
}

static void CalculaHoras(
    tData *dataEntrada,
    tData *dataSaida,
    float *horasDiasUteis,
    float *horasFinaisDeSemana
) {
    *horasDiasUteis = 0;
    *horasFinaisDeSemana = 0;

    tData *i = CriaData();
    CopiaDiaMesAno(dataEntrada, i);
    DataDiaSeguinte(i);

    float horasDataEntrada = CalculaHorasEntreDatas(dataEntrada, i);
    if (DataEhSabadoOuDomingo(dataEntrada)) {
        *horasFinaisDeSemana += horasDataEntrada;
    } else {
        *horasDiasUteis += horasDataEntrada;
    }

    while (ComparaDiaMesAno(i, dataSaida) < 0) {
        if (DataEhSabadoOuDomingo(i)) {
            *horasFinaisDeSemana += HORAS_EM_UM_DIA;
        } else {
            *horasDiasUteis += HORAS_EM_UM_DIA;
        }

        DataDiaSeguinte(i);
    }

    float horasDataSaida = CalculaHorasEntreDatas(i, dataSaida);
    if (DataEhSabadoOuDomingo(i)) {
        *horasFinaisDeSemana += horasDataSaida;
    } else {
        *horasDiasUteis += horasDataSaida;
    }

    DestroiData(i);
}
