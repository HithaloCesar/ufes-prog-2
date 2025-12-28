#include "agendatarefas.h"
#include <stdlib.h>

struct tarefa {
    int prioridade;
    void *tarefa;
    void (*destruir)(void *);
    void (*executar)(void *);
};

struct agendatarefas {
    struct tarefa **tarefas;
    int qtdTarefas;
    int maxTarefas;
};

tAgendaTarefas *CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas *agenda = calloc(1, sizeof(*agenda));

    agenda->maxTarefas = numElem;
    agenda->tarefas = calloc(numElem, sizeof(agenda->tarefas));

    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas *agenda) {
    free(agenda->tarefas);
    free(agenda);
}

void CadastraTarefaNaAgenda(
    tAgendaTarefas *agenda,
    int prioridade,
    void *tarefa,
    void (*executa)(void *),
    void (*destroi)(void *)
) {
    struct tarefa *t = calloc(1, sizeof(*t));
    t->prioridade = prioridade;
    t->tarefa = tarefa;
    t->executar = executa;
    t->destruir = destroi;

    if (agenda->qtdTarefas == agenda->maxTarefas) {
        agenda->maxTarefas *= 2;
        agenda->tarefas = realloc(
            agenda->tarefas, agenda->maxTarefas * sizeof(*agenda->tarefas)
        );
    }

    agenda->tarefas[agenda->qtdTarefas++] = t;
}

static int ComparaTarefas(const void *a, const void *b) {
    struct tarefa *t1 = *(struct tarefa **)a;
    struct tarefa *t2 = *(struct tarefa **)b;

    return t2->prioridade - t1->prioridade;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas *agenda) {
    qsort(
        agenda->tarefas,
        agenda->qtdTarefas,
        sizeof(*agenda->tarefas),
        ComparaTarefas
    );

    for (int i = 0; i < agenda->qtdTarefas; i++) {
        struct tarefa *t = agenda->tarefas[i];
        t->executar(t->tarefa);
        t->destruir(t->tarefa);
        free(agenda->tarefas[i]);
    }
}
