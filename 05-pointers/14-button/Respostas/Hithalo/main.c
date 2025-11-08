#include <stdlib.h>
#include <stdio.h>
#include "tela.h"

static void BotaoSalvar(void) {
    printf("- Botao de SALVAR dados ativado!\n");
}

static void BotaoExcluir(void) {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

static void BotaoOpcoes(void) {
    printf("- Botao de OPCOES ativado!\n");
}

int main(void) {
    Tela tela = CriarTela(200, 400);

    Botao botao;

    botao = CriarBotao("Salvar", 12, "FFF", 1, BotaoSalvar);
    RegistraBotaoTela(&tela, botao);

    botao = CriarBotao("Excluir", 18, "000", 1, BotaoExcluir);
    RegistraBotaoTela(&tela, botao);

    botao = CriarBotao("Opcoes", 10, "FF0000", 2, BotaoOpcoes);
    RegistraBotaoTela(&tela, botao);

    DesenhaTela(tela);

    OuvidorEventosTela(tela);

    return EXIT_SUCCESS;
}
