#ifndef REGISTRO_H
#define REGISTRO_H

#include "jogador.h"

#define NUM_JOGADOR_PARTIDA 2

typedef struct {
    int idJogador1;
    int idJogador2;
    int idVencedor;
    int qtdeRecursos1;
    int qtdeRecursos2;
} Registro;

/*
Função que lê apenas um registro de partida a partir da entrada padrão.
O registro de uma partida é composto das informações de 5 jogadores.
Verifique a especificação da atividade para mais detalhes.

@param idPartida: ID do jogador 1
@return Registro: Registro de uma partida
*/
Registro leRegistro(int idJogador1);

/*
Função que recupera o id do primeiro jogador da partida.

@param r: Registro de uma partida
*/
int getIdJogador1doRegistro(Registro r);

/*
Função que recupera o id do segundo jogador da partida.

@param r: Registro de uma partida
*/
int getIdJogador2doRegistro(Registro r);

/*
Função que recupera o id do vencedor da partida.

@param r: Registro de uma partida
*/
int getIdVencedordoRegistro(Registro r);

/*
Função que recupera a quantidade de recursos do primeiro jogador da partida.

@param r: Registro de uma partida
*/
int getQtdeRecursos1doRegistro(Registro r);

/*
Função que recupera a quantidade de recursos do primeiro jogador da partida.

@param r: Registro de uma partida
*/
int getQtdeRecursos2doRegistro(Registro r);


#endif
