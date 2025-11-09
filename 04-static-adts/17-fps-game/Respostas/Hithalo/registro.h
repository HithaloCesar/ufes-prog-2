#ifndef REGISTRO_H
#define REGISTRO_H

#include "jogador.h"

#define MAX_JOGADOR_PARTIDA 5

typedef struct {
    int idPartida;
    Jogador jogadores[MAX_JOGADOR_PARTIDA];
} Registro;

/**
 * Função que lê apenas um registro de partida a partir da entrada padrão.
 * O registro de uma partida é composto das informações de 5 jogadores.
 * Verifique a especificação da atividade para mais detalhes.
 *
 * @param idPartida ID da partida.
 * @return Registro de uma partida.
 */
Registro leRegistro(int idPartida);

/**
 * Função que busca um jogador em um registro de partida a partir do ID do
 * jogador.
 * Se o jogador for encontrado, ele é retornado.
 * Caso contrário, um jogador é criado com ID -1 e retornado.
 *
 * @param r Registro de uma partida.
 * @param idJog ID do jogador a ser buscado.
 */
Jogador buscaJogadorRegistro(Registro r, int idJog);

#endif
