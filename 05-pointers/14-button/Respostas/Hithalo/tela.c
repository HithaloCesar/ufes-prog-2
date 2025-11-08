#include "tela.h"
#include <stdlib.h>
#include <stdio.h>

Tela CriarTela(int altura, int largura) {
    Tela tela;
    tela.altura = altura;
    tela.largura = largura;
    tela.qntBotoes = 0;

    return tela;
}

void RegistraBotaoTela(Tela *t, Botao b) {
    t->botoes[t->qntBotoes++] = b;
}

void DesenhaTela(Tela t) {
    printf("##################\n");
    for (int i = 0; i < t.qntBotoes; i++) {
        DesenhaBotao(t.botoes[i], i);
        putchar('\n');
    }
    printf("##################\n");
}

void OuvidorEventosTela(Tela t) {
    printf("- Escolha sua acao: ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao < 0 || opcao > 2) {
        exit(EXIT_FAILURE);
    }

    ExecutaBotao(t.botoes[opcao]);
}
