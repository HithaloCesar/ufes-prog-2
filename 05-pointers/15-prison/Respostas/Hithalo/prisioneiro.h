#ifndef PRISIONEIRO_H
#define PRISIONEIRO_H

#define MAX_TAM_NOME 100
#define MAX_TAM_PRISIONEIRO 100

typedef struct Prisioneiro {
    char nome[MAX_TAM_NOME];
    int pena;
    int tempoPassado;
} tPrisioneiro;

/**
 * @brief Cria o prisioneiro a partir dos parâmetros fornecidos.
 * @param nome Nome do prisioneiro.
 * @param pena Pena a ser cumprida pelo prisioneiro.
 */
tPrisioneiro criaPrisioneiro(char *nome, int pena);

/**
 * @brief Aumenta o tempo passado do prisioneiro.
 */
void passaTempoPrisioneiro(tPrisioneiro *prisioneiro);

/**
 * @brief Imprime a fuga do prisioneiro na tela e chama a função de
 *        desalocação.
 */
void fogePrisioneiro(tPrisioneiro *prisioneiro);

/**
 * @brief Retorna 1 quando a pena do prisioneiro termina.
 */
int acabouPenaPrisioneiro(tPrisioneiro *prisioneiro);

/**
 * @brief Imprime a liberação do prisioneiro na tela.
 */
void liberaPrisioneiroCumpriuPena(tPrisioneiro *prisioneiro);

/**
 * @brief Imprime a liberação do prisioneiro na tela para encerrar o programa.
 */
void liberaPrisioneiroFimPrograma(tPrisioneiro *prisioneiro);

#endif
