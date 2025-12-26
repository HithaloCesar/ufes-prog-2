#include "cidade.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "defesa.h"
#include "missil.h"

struct cidade {
    char nome[MAX_NOME];
    float x, y;

    tDefesa defesas[QTD_DEF];
    int qtdDef;

    tMissil misseis[QTD_MIS];
    int qtdMis;

    float danoPossivel;
    float danoReal;
};

tCidade CriaCidade(void) {
    tCidade cidade = calloc(1, sizeof(*cidade));

    return cidade;
}

tCidade LeEntrada(tCidade cidade) {
    scanf("C %f %f", &cidade->x, &cidade->y);

    bool continuaLeitura = true;
    while (continuaLeitura) {
        char c;
        scanf(" %c", &c);

        switch (c) {
            case DEFESA: {
                cidade->defesas[cidade->qtdDef++] = LeDefesa();
                break;
            }
            case MISSIL: {
                cidade->misseis[cidade->qtdMis++] = LeMissil();
                break;
            }
            case ENCERRAR: {
                getchar();
                continuaLeitura = false;
                break;
            }
        }
    }

    return cidade;
}

void ImprimeCidade(tCidade cidade) {
    // ???
}

void LiberaCidade(tCidade cidade) {
    for (int i = 0; i < cidade->qtdDef; i++) {
        LiberaDefesa(cidade->defesas[i]);
    }

    for (int i = 0; i < cidade->qtdMis; i++) {
        LiberaMissil(cidade->misseis[i]);
    }

    free(cidade);
}

void ProcessaAtaques(tCidade cidade) {
    for (int i = 0; i < cidade->qtdMis; i++) {
        tMissil m = cidade->misseis[i];

        float m_x = GetMissilX(cidade->misseis[i]);
        float m_y = GetMissilY(cidade->misseis[i]);
        float m_p = GetMissilPoder(m);
        if (m_x < 0 || m_x > cidade->x || m_y < 0 || m_y > cidade->y) {
            ReduzPoder(m, m_p);
            continue;
        }

        cidade->danoPossivel += m_p;

        for (int i = 0; i < cidade->qtdDef; i++) {
            tDefesa d = cidade->defesas[i];
            if (PodeDefender(d) && VerificaSeDentroArea(d, m_x, m_y)) {
                ReduzPoder(m, GetDefesaPoder(d));
                UsaDefesa(d);
            }
        }

        cidade->danoReal += GetMissilPoder(m);
    }
}

void ImprimeDados(tCidade cidade) {
    for (int i = 0; i < cidade->qtdDef; i++) {
        ImprimeDefesa(cidade->defesas[i]);
    }
    for (int i = 0; i < cidade->qtdMis; i++) {
        ImprimeMissil(cidade->misseis[i]);
    }

    float danoMitigado = cidade->danoPossivel - cidade->danoReal;
    printf("Efetividade: %.2f%%\n", 100 * danoMitigado / cidade->danoPossivel);
}
