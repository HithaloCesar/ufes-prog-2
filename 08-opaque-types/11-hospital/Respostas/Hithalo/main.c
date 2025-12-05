#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "paciente.h"

#define QTD_INICIAL_PACIENTES 10
#define DIA_HOJE 12
#define MES_HOJE 9
#define ANO_HOJE 2023

typedef enum {
    OPERACAO_ADICIONAR_PACIENTE = 'P',
    OPERACAO_ADICIONAR_LESAO = 'L',
    OPERACAO_FINALIZAR_PROGRAMA = 'F'
} Operacao;

static int OperacaoAdicionarPaciente(
    Paciente **pacientes,
    size_t *tamanhoPacientes,
    size_t *qtdPacientes
);

static int OperacaoAdicionaLesao(Paciente **pacientes, size_t qtdPacientes);

static void OperacaoFinalizarPrograma(
    Paciente **pacientes,
    size_t qtdPacientes
);

static void freePacientes(Paciente **pacientes, size_t qtdPacientes);

int main(void) {
    Paciente **pacientes = malloc(QTD_INICIAL_PACIENTES * sizeof(*pacientes));
    size_t tamanhoPacientes = QTD_INICIAL_PACIENTES;
    size_t qtdPacientes = 0;

    char operacao;
    bool executar = true;
    while (executar) {
        scanf(" %c\n", &operacao);

        switch (operacao) {
            case OPERACAO_ADICIONAR_PACIENTE: {
                int sucesso = !OperacaoAdicionarPaciente(
                    pacientes,
                    &tamanhoPacientes,
                    &qtdPacientes
                );
                if (!sucesso) {
                    freePacientes(pacientes, qtdPacientes);
                    return EXIT_FAILURE;
                }
                break;
            }

            case OPERACAO_ADICIONAR_LESAO: {
                if (OperacaoAdicionaLesao(pacientes, qtdPacientes)) {
                    return EXIT_FAILURE;
                }
                break;
            }

            case OPERACAO_FINALIZAR_PROGRAMA: {
                OperacaoFinalizarPrograma(pacientes, qtdPacientes);
                executar = false;
                break;
            }

            default: {
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}

static int OperacaoAdicionarPaciente(
    Paciente **pacientes,
    size_t *tamanhoPacientes,
    size_t *qtdPacientes
) {
    if (*qtdPacientes == *tamanhoPacientes) {
        Paciente **novoPacientes;
        *tamanhoPacientes += QTD_INICIAL_PACIENTES;
        novoPacientes = realloc(
            pacientes, *tamanhoPacientes * sizeof(*pacientes)
        );
        if (novoPacientes == NULL) {
            return 1;
        }
        pacientes = novoPacientes;
    }

    pacientes[*qtdPacientes] = lerPaciente();
    if (pacientes[*qtdPacientes] == NULL) {
        return 1;
    }
    (*qtdPacientes)++;

    return 0;
}

static int OperacaoAdicionaLesao(Paciente **pacientes, size_t qtdPacientes) {
    Lesao *lesao = lerLesao();
    bool PacienteEncontrado = false;
    for (size_t i = 0; i < qtdPacientes; i++) {
        char *cartaoSusPaciente = getCartaoSusPaciente(pacientes[i]);
        if (!strcmp(getCartaoSusLesao(lesao), cartaoSusPaciente)) {
            PacienteEncontrado = true;
            int qtdInicialLesoes = getNumLesoesPaciente(pacientes[i]);
            adicionaLesaoPaciente(pacientes[i], lesao);
            int qtdFinalLesoes = getNumLesoesPaciente(pacientes[i]);
            if (qtdFinalLesoes == qtdInicialLesoes) {
                liberaLesao(lesao);
                freePacientes(pacientes, qtdPacientes);
                return 1;
            }
            break;
        }
    }

    if (!PacienteEncontrado) {
        liberaLesao(lesao);
    }

    return 0;
}

static void OperacaoFinalizarPrograma(
    Paciente **pacientes,
    size_t qtdPacientes
) {
    int soma_idades = 0;
    int totalLesoes = 0;
    int totalCirurgias = 0;
    Data *hoje = criaData(DIA_HOJE, MES_HOJE, ANO_HOJE);
    for (size_t i = 0; i < qtdPacientes; i++) {
        soma_idades += calculaIdadePaciente(pacientes[i], hoje);
        totalLesoes += getNumLesoesPaciente(pacientes[i]);
        totalCirurgias += qtdLesoesCirurgicasPaciente(pacientes[i]);
    }
    free(hoje);

    printf("TOTAL PACIENTES: %zu\n", qtdPacientes);
    printf("MEDIA IDADE (ANOS): ");
    if (qtdPacientes > 0) {
        printf("%d\n", soma_idades / (int)qtdPacientes);
    } else {
        printf("-\n");
    }
    printf("TOTAL LESOES: %d\n", totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (size_t i = 0; i < qtdPacientes; i++) {
        imprimePaciente(pacientes[i]);
    }

    freePacientes(pacientes, qtdPacientes);
}

static void freePacientes(Paciente **pacientes, size_t qtdPacientes) {
    for (size_t i = 0; i < qtdPacientes; i++) {
        liberaPaciente(pacientes[i]);
    }
    free(pacientes);
}
