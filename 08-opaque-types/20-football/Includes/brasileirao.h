#ifndef _BRASILEIRAO_H
#define _BRASILEIRAO_H

#include "time.h"
#include "tabela.h"
#define MAX_TIMES 20

typedef struct _BRA BRA;

/**
 * @brief Construtor do campeonato. Lê da entrada padrão número de times,
 *        número de rodadas e pontuação.
 */
BRA *CriaCamp();

/**
 * @brief Lê da entrada padrão as partidas da rodada, computa os resultados e
 *        atualiza a tabela.
 */
void RealizaRodada(BRA *br);

/**
 * @brief Imprime o menu e trata cada opção.
 */
void RealizaCamp(BRA *br);

/**
 * @brief Lê 2 nomes da entrada padrão e remove os times correspondentes da
 *        competição.
 */
void RemoveTimesCamp(BRA *br);

/**
 * @brief Libera a memoria do campeonato.
 */
void DesalocaCamp(BRA *br);

/**
 * @brief Imprime a tabela final, premiação e desaloca o campeonato.
 */
void FinalizaCamp(BRA *br);

#endif
