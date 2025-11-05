#include "pessoa.h"
#include <stdlib.h>
#include <stdio.h>

tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    pessoa.nome[0] = '\0';

    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    scanf(" %[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    return pessoa->mae != NULL || pessoa->pai != NULL;
}

void ImprimePessoa(tPessoa *pessoa) {
    if (!VerificaSeTemPaisPessoa(pessoa)) {
        return;
    }

    printf("NOME COMPLETO: %s\n", pessoa->nome);

    if (pessoa->pai == NULL) {
        printf("PAI: NAO INFORMADO\n");
    } else {
        printf("PAI: %s\n", pessoa->pai->nome);
    }

    if (pessoa->mae == NULL) {
        printf("MAE: NAO INFORMADO\n");
    } else {
        printf("MAE: %s\n", pessoa->mae->nome);
    }

    if (pessoa->irmao == NULL) {
        printf("IRMAO: NAO INFORMADO\n");
    } else {
        printf("IRMAO: %s\n", pessoa->irmao->nome);
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    if (pessoa1->mae == NULL || pessoa1->pai == NULL) {
        return 0;
    }

    return pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas) {
    int numAssociacoes;
    scanf("%d", &numAssociacoes);

    int maeIndice, paiIndice, filhoIndice;

    for (int i = 0; i < numAssociacoes; i++) {
        scanf("%*[^0-9-] %d %*[^0-9-] %d %*[^0-9-] %d",
            &maeIndice, &paiIndice, &filhoIndice
        );
        if (maeIndice != -1) {
            pessoas[filhoIndice].mae = &pessoas[maeIndice];
        }
        if (paiIndice != -1) {
            pessoas[filhoIndice].pai = &pessoas[paiIndice];

        }
    }

    for (int i = 0; i < numPessoas; i++) {
        for (int j = i + 1; j < numPessoas; j++) {
            if (VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])) {
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}
