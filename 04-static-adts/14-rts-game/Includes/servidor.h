#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "registro.h"

#define MAX_PARTIDAS 1000
#define MAX_JOGADORES 100

typedef struct {
    Registro partidas[MAX_PARTIDAS];
    Jogador jogadores[MAX_JOGADORES];
    int nPartidas;
    int nJogadores;
} Servidor;

/*
Função que lê todos os registros de partidas de um servidor a partir da entrada
padrão e retorna um servidor com todos os registros de partidas lidos.
Conforme a especificação da atividade, a leitura é encerrada quando um ID de
partida igual a -1 é lido.

@return Servidor: Servidor com todos os registros de partidas lidos
*/
Servidor leRegistrosServidor();


/*
Função que processa todos os registros de partidas de um servidor, fazendo todo
o processamento com relação aos jogadores cadastrados no servidor.
Um jogador é cadastrado no processamento da primeira partida que envolve ele.

@return Servidor: Servidor com todos os registros de partidas e jogadores
        atualizados
*/
Servidor processaPartidas(Servidor s);


/*
Função que recebe um servidor já preenchido com os dados de todas as partidas e
um ID de jogador. A partir dessas informações, ela busca em qual posição do
vetor de jogadores esse jogador está registrado.
Se o jogar não for encontrado, -1 é criado e retornado.

@param s: Servidor
@param idJog: ID do jogador
*/
int buscaPosicaoJogadorServidor(Servidor s, int idJog);


/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com
as estatísticas de um conjunto de jogadores solicitados a partir da entrada
padrão.
O relatório é impresso conforme o formato especificado na descrição da
atividade.
*/
void criaRelatorioServidor(Servidor s);

#endif
