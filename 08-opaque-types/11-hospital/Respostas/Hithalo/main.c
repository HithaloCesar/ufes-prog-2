#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "paciente.h"
#include "lesao.h"

#define MAX_PACIENTES 100
#define DIA_BASE 19
#define MES_BASE 9
#define ANO_BASE 2023

typedef enum {
    OPERACAO_ADICIONAR_PACIENTE = 'P',
    OPERACAO_ADICIONA_LESAO = 'L',
    OPERACAO_FINALIZAR_PROGRAMA = 'F'
} Operacao;

static void imprimeRelatorio(Paciente **pacientes, int qtdPacientes);
static Paciente *encontraPaciente(
    Paciente **pacientes,
    int qtdPacientes,
    char *cartaoSus
);

int main(void) {
    Paciente **pacientes = calloc(MAX_PACIENTES, sizeof(*pacientes));
    int qtdPacientes = 0;

    bool continuarExecucao = true;
    while (continuarExecucao) {
        char operacao;
        scanf(" %c", &operacao);
        getchar();

        switch (operacao) {
            case OPERACAO_ADICIONAR_PACIENTE: {
                pacientes[qtdPacientes++] = lerPaciente();
                break;
            }
            case OPERACAO_ADICIONA_LESAO: {
                Lesao *l = lerLesao();
                Paciente *p = encontraPaciente(
                    pacientes, qtdPacientes, getCartaoSusLesao(l)
                );
                if (!p) {
                    liberaLesao(l);
                    break;
                }
                adicionaLesaoPaciente(p, l);
                break;
            }
            case OPERACAO_FINALIZAR_PROGRAMA: {
                continuarExecucao = false;
                break;
            }
        }
    }

    imprimeRelatorio(pacientes, qtdPacientes);

    for (int i = 0; i < qtdPacientes; i++) {
        liberaPaciente(pacientes[i]);
    }
    free(pacientes);

    return EXIT_SUCCESS;
}

static void imprimeRelatorio(Paciente **pacientes, int qtdPacientes) {
    Data *diaBase = criaData(DIA_BASE, MES_BASE, ANO_BASE);
    int somaIdades = 0;
    int qtdLesoes = 0;
    int qtdCirurgias = 0;
    for (int i = 0; i < qtdPacientes; i++) {
        somaIdades += calculaIdadePaciente(pacientes[i], diaBase);
        qtdLesoes += getNumLesoesPaciente(pacientes[i]);
        qtdCirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
    }
    liberaData(diaBase);

    printf("TOTAL PACIENTES: %d\n", qtdPacientes);
    if (qtdPacientes > 0) {
        printf("MEDIA IDADE (ANOS): %d\n", somaIdades / qtdPacientes);
    } else {
        printf("MEDIA IDADE (ANOS): -\n");
    }
    printf("TOTAL LESOES: %d\n", qtdLesoes);
    printf("TOTAL CIRURGIAS: %d\n", qtdCirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < qtdPacientes; i++) {
        imprimePaciente(pacientes[i]);
    }
}

static Paciente *encontraPaciente(
    Paciente **pacientes,
    int qtdPacientes,
    char *cartaoSus
) {
    for (int i = 0; i < qtdPacientes; i++) {
        if (!strcmp(getCartaoSusPaciente(pacientes[i]), cartaoSus)) {
            return pacientes[i];
        }
    }

    return NULL;
}
