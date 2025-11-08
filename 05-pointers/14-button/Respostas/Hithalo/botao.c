#include "botao.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void SetarTexto(Botao *b, char *novoTexto) {
    strcpy(b->texto, novoTexto);
}

void SetarTamFonte(Botao *b, int novoTamFonte) {
    b->tamFonte = novoTamFonte;
}

void SetarCor(Botao *b, char *novaCor) {
    strcpy(b->corHex, novaCor);
}

void SetarTipo(Botao *b, int novoTipo) {
    b->tipo = novoTipo;
}

Botao CriarBotao(
    char *texto,
    int tamFonte,
    char *cor,
    int tipo,
    void (*executa)(void)
) {
    Botao botao;
    SetarTexto(&botao, texto);
    SetarTamFonte(&botao, tamFonte);
    SetarCor(&botao, cor);
    SetarTipo(&botao, tipo);
    botao.executa = executa;

    return botao;
}

void ExecutaBotao(Botao b) {
    char tipo[MAX_TAM_TEXTO];
    switch (b.tipo) {
        case 1: {
            strcpy(tipo, "click");
            break;
        }
        case 2: {
            strcpy(tipo, "longo click");
            break;
        }
        case 3: {
            strcpy(tipo, "hover");
            break;
        }
    }

    printf("- Executando o botao com evento de %s\n", tipo);

    b.executa();
}

void DesenhaBotao(Botao b, int idx) {
    printf("-------------\n");
    printf("- Botao [%d]:\n", idx);
    printf("(%s | %s | %d | %d)\n", b.texto, b.corHex, b.tamFonte, b.tipo);
    printf("-------------\n");
}
