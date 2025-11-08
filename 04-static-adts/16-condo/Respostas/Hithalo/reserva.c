#include "reserva.h"
#include <stdio.h>

Reserva criaReserva(
    Morador morRes,
    Area aRes,
    Data dRes,
    int qtdConvidados,
    char turno
) {
    Reserva r;
    r.morador = morRes;
    r.area = aRes;
    r.data = dRes;
    r.qtdConvidados = qtdConvidados;
    r.turno = turno;

    return r;
}

void lerDadosSolicitacaoReserva(
    char *idArea,
    char *cpf,
    Data *dt,
    int *qtdConv,
    char *turno
) {
    scanf(" %[^\n]", idArea);
    scanf(" %[^\n]", cpf);
    *dt = lerData();
    scanf("%d", qtdConv);
    scanf(" %c", turno);
}

int verificaSolicitacaoReserva(
    Reserva *agendaReservas,
    int nRes,
    Morador morRes,
    Area aRes,
    Data dRes,
    int qtdConvidados,
    char turno
) {
    if (calculaIdadeMorador(morRes, dRes) < 21) {
        return 0;
    }

    if (qtdConvidados > getCapacidadeArea(aRes)) {
        return 0;
    }

    for (int i = 0; i < nRes; i++) {
        if (comparaData(agendaReservas[i].data, dRes)) {
            if (comparaMorador(morRes, agendaReservas[i].morador)) {
                return 0;
            }
            if (comparaArea(aRes, agendaReservas[i].area)
                && turno == agendaReservas[i].turno) {
                return 0;
            }
        }
    }

    return 1;
}

void imprimeReserva(Reserva r) {
    printf("--------- RESERVA -----------\n");
    printf("Morador:\n");
    imprimeMorador(r.morador);
    putchar('\n');

    printf("Area reservada:\n");
    imprimeArea(r.area);
    printf("Data da reserva: ");
    imprimeData(r.data);
    printf("Turno da reserva: %c\n", r.turno);
    putchar('\n');

    printf("Quantidade de convidados: %d\n", r.qtdConvidados);
    printf("Taxa de ocupacao: %d%%\n",
        100 * r.qtdConvidados / getCapacidadeArea(r.area)
    );
    printf("------------------------------\n");
}
