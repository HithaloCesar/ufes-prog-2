#ifndef JOGADOR_H
#define JOGADOR_H

#include <string.h>

#define MAX_LEAGUE 15

typedef struct {
    int id;
    int vitorias;
    int derrotas;
    int empates;
    int pontuacao;
    char league[MAX_LEAGUE];
} Jogador;

/*
Função que inicializa um jogador com ID passado por parâmetro.
Todas as estatísticas do jogador são inicializadas com 0 e o valor da league é
inicializado com ROOKIE.

@param id: ID do jogador
@return Jogador: Jogador inicializado
*/
Jogador inicializaJogador(int id);

/*
Função que calcula a liga (league) de um jogador e armazena no campo league do
próprio jogador.

@param j: Jogador
@return Uma string fixa que representa a categoria do jogador. ex: return
        "BRONZE";
*/
char* calculaLeague(Jogador j);

/*
Funçao que recebe um jogador e imprime suas informações conforme o formato
especificado.

@param j: Jogador
*/
void printaJogador(Jogador j);

/*
Funçao que recebe um jogador e retorna o valor de ID do jogador.

@param j: Jogador
@return int: ID do jogador
*/
int getIdJogador(Jogador j);

/*
Funçao que recebe um jogador e uma pontuação (positiva ou negativa) a ser
somada na pontuação do jogador.
Demais processamentos relacionados a pontuação de um jogador podem ser feitos
nela também.

@param j: Jogador
@param pont: pontuação (positiva ou negativa) a ser SOMADA na pontuação do jogador
@return Jogador: Jogador com pontuação atualizada.
*/
Jogador somaPontuacaoJogador(Jogador j, int pont);

/*
Funçao que recebe um jogador, atualiza seu número de vitórias (somando UM), e o
retorna.

@param j: Jogador
@return Jogador: Jogador com número de vitórias atualizado.
*/
Jogador adicionaVitoriaAoJogador(Jogador j);

/*
Funçao que recebe um jogador, atualiza seu número de vitórias (somando UM), e o
retorna.

@param j: Jogador
@return Jogador: Jogador com número de derrotas atualizado.
*/
Jogador adicionaDerrotaAoJogador(Jogador j);

/*
Funçao que recebe um jogador, atualiza seu número de vitórias (somando UM), e o
retorna.

@param j: Jogador
@return Jogador: Jogador com número de empates atualizado.
*/
Jogador adicionaEmpateAoJogador(Jogador j);

#endif
