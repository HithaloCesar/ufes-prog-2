#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

tData *CriaData(void) {
    tData *d = calloc(1, sizeof(*d));

    return d;
}

void LeData(tData *d) {
    scanf("%d/%d/%d", &d->dia, &d->mes, &d->ano);
    getchar();
}

void LiberaData(tData *d) {
    free(d);
}

int VerificaDataValida(tData *d) {
    if (d->mes <= 0 || d->mes > 12) {
        return 0;
    }

    return (d->dia > 0 && d->dia <= NumeroDiasMes(d));
}

void ImprimeMesExtenso(tData *d) {
    switch (d->mes) {
        case 1: {
            printf("Janeiro");
            break;
        }
        case 2: {
            printf("Fevereiro");
            break;
        }
        case 3: {
            printf("Março");
            break;
        }
        case 4: {
            printf("Abril");
            break;
        }
        case 5: {
            printf("Maio");
            break;
        }
        case 6: {
            printf("Junho");
            break;
        }
        case 7: {
            printf("Julho");
            break;
        }
        case 8: {
            printf("Agosto");
            break;
        }
        case 9: {
            printf("Setembro");
            break;
        }
        case 10: {
            printf("Outubro");
            break;
        }
        case 11: {
            printf("Setembro");
            break;
        }
        case 12: {
            printf("Dezembro");
            break;
        }
    }
}

void ImprimeDataExtenso(tData *d) {
    printf("%02d de ", d->dia);
    ImprimeMesExtenso(d);
    printf(" de %d", d->ano);
    putchar('\n');
}

int VerificaBissexto(tData *d) {
    return (d->ano % 4 == 0 && d->ano % 100 != 0) || d->ano % 400 == 0;
}

int NumeroDiasMes(tData *d) {
    if (d->mes == 2) {
        return VerificaBissexto(d) ? 29 : 28;
    }

    if (d->mes == 4 || d->mes == 6 || d->mes == 9 || d->mes == 11) {
        return 30;
    }

    return 31;
}

int ComparaData(tData *d1, tData *d2) {
    if (d1->ano != d2->ano) {
        return d1->ano - d2->ano > 0 ? 1 : -1;
    }

    if (d1->mes != d2->mes) {
        return d1->mes - d2->mes > 0 ? 1 : -1;
    }

    if (d1->dia != d2->dia) {
        return d1->dia - d2->dia > 0 ? 1 : -1;
    }

    return 0;
}

int CalculaDiasAteMes(tData *d) {
    tData *dataIndiceI = CriaData();
    dataIndiceI->ano = d->ano;

    int dias = 0;
    for (int i = 1; i < d->mes; i++) {
        dataIndiceI->mes = i;
        dias += NumeroDiasMes(dataIndiceI);
    }

    LiberaData(dataIndiceI);

    return dias;
}

int CalculaDiferencaDias(tData *d1, tData *d2) {
    int diff = ComparaData(d1, d2);

    if (diff == 0) {
        return 0;
    }

    if (diff > 0) {
        tData *aux = d1;
        d1 = d2;
        d2 = aux;
    }

    int diasAteData1 = CalculaDiasAteMes(d1) + d1->dia;
    int diasAteData2 = CalculaDiasAteMes(d2) + d2->dia;

    if (d1->ano == d2->ano) {
        return diasAteData2 - diasAteData1;
    }

    tData *i = CriaData();
    int diasDeAnosInteirosAteData2 = 0;
    for (i->ano = d1->ano; i->ano < d2->ano; i->ano++) {
        diasDeAnosInteirosAteData2 += VerificaBissexto(i) ? 366 : 365;
    }
    LiberaData(i);

    return diasDeAnosInteirosAteData2 - diasAteData1 + diasAteData2;
}
