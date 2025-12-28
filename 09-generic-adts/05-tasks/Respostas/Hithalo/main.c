#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"

enum tarefa_tipo {
    TAREFA_TIPO_IMPRIME = 'I',
    TAREFA_TIPO_SOMA = 'S',
    TAREFA_TIPO_MULTIPLICA = 'M'
};

static bool ValidaTipo(char c);
static void TarefaImprime(tAgendaTarefas *agenda, int prioridade);
static void TarefaSoma(tAgendaTarefas *agenda, int prioridade);
static void TarefaMultiplica(tAgendaTarefas *agenda, int prioridade);

int main(void) {
    puts("Digite o numero de tarefas:");
    int qtdTarefas;
    scanf("%d", &qtdTarefas);
    getchar();

    tAgendaTarefas *agenda = CriaAgendaDeTarefas(qtdTarefas);

    for (int i = 0; i < qtdTarefas; i++) {
        int prioridade;
        char tipo;

        bool leituraOk = false;
        while (!leituraOk) {
            scanf("%d %c", &prioridade, &tipo);

            if (!ValidaTipo(tipo)) {
                puts("Digite um tipo de tarefa suportado (I/S/M))");
                char c;
                while ((c = getchar()) != '\n');
                continue;
            }

            leituraOk = true;
        }

        switch (tipo) {
            case TAREFA_TIPO_IMPRIME: {
                TarefaImprime(agenda, prioridade);
                break;
            }
            case TAREFA_TIPO_SOMA: {
                TarefaSoma(agenda, prioridade);
                break;
            }
            case TAREFA_TIPO_MULTIPLICA: {
                TarefaMultiplica(agenda, prioridade);
                break;
            }
        }

    }

    ExecutarTarefasDaAgenda(agenda);

    DestroiAgendaDeTarefas(agenda);

    return EXIT_SUCCESS;
}

static bool ValidaTipo(char c) {
    switch (c) {
        case TAREFA_TIPO_IMPRIME:
        case TAREFA_TIPO_SOMA:
        case TAREFA_TIPO_MULTIPLICA:
            return true;
        default:
            return false;
    }
}

static void TarefaImprime(tAgendaTarefas *agenda, int prioridade) {
    char *msg;
    scanf(" %m[^\n]", &msg);
    getchar();
    void *tarefa = CriaTarefaImprimir(msg);
    CadastraTarefaNaAgenda(
        agenda,
        prioridade,
        tarefa,
        ExecutaTarefaImprimir,
        DestroiTarefaImprimir
    );
    free(msg);
}

static void TarefaSoma(tAgendaTarefas *agenda, int prioridade) {
    float n1, n2;
    scanf("%f %f", &n1, &n2);
    getchar();
    void *tarefa = CriaTarefaSoma(n1, n2);
    CadastraTarefaNaAgenda(
        agenda,
        prioridade,
        tarefa,
        ExecutaTarefaSoma,
        DestroiTarefaSoma
    );
}

static void TarefaMultiplica(tAgendaTarefas *agenda, int prioridade) {
    float n1, n2;
    scanf("%f %f", &n1, &n2);
    getchar();
    void *tarefa = CriaTarefaMultiplicar(n1, n2);
    CadastraTarefaNaAgenda(
        agenda,
        prioridade,
        tarefa,
        ExecutaTarefaMultiplicar,
        DestroiTarefaMultiplicar
    );
}
