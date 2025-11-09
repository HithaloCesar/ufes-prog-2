#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct {
    int id;
    int kills;
    int deaths;
    int assists;
    float valorKDA;
} Jogador;

/**
 * Função que inicializa um jogador com ID passado por parâmetro.
 * Todas as estatísticas do jogador são inicializadas com 0 e o valor do KDA é
 * inicializado com -1.
 *
 * @param id ID do jogador
 * @return Jogador inicializado
 */
Jogador inicializaJogador(int id);

/**
 * Função que lê as estatísticas de um jogador a partir da entrada padrão e
 * retorna um jogador inicializado com essas estatísticas.
 *
 * O ID do jogador é passado por parâmetro. Uma vez lido as estatísticas, o
 * valor do KDA é calculado e armazenado no jogador.
 *
 * @param id ID do jogador.
 * @return Jogador inicializado com as estatísticas lidas e o valor do KDA
 *         calculado.
 */
Jogador leJogador(int id);

/**
 * Função que calcula o valor do KDA de um jogador e armazena no campo valorKDA
 * do próprio jogador.
 *
 * @param j Jogador.
 * @return Valor do KDA do jogador.
 */
float calculaKDA(Jogador j);

/**
 * Essa função recebe um jogador cadastrado e atualiza suas estatísticas de
 * acordo com os valores passados por parâmetro.
 * O ID do jogador é sempre igualado ao ID passado por parâmetro e as
 * estatísticas de kills, deaths e assists são incrementadas pelos valores
 * passados por parâmetro.
 * O valor do KDA é recalculado e armazenado no campo valorKDA do jogador.
 *
 * @param j Jogador.
 * @param id ID do jogador.
 * @param k Kills a serem incrementadas.
 * @param d Deaths a serem incrementadas.
 * @param a Assists a serem incrementadas.
 * @return Jogador atualizado.
 */
Jogador atualizaJogador(Jogador j, int id, int k, int d, int a);

/**
 * Função que recebe um jogador e retorna o valor de kills do jogador.
 *
 * @param j Jogador.
 * @return Kills do jogador.
 */
int getKillsJogador(Jogador j);

/**
 * Função que recebe um jogador e retorna o valor de deaths do jogador.
 *
 * @param j Jogador.
 * @return Deaths do jogador.
 */
int getDeathsJogador(Jogador j);

/**
 * Função que recebe um jogador e retorna o valor de assists do jogador.
 *
 * @param j Jogador.
 * @return Assists do jogador.
 */
int getAssistsJogador(Jogador j);

/**
 * Função que recebe um jogador e retorna o valor de ID do jogador.
 *
 * @param j Jogador.
 * @return ID do jogador.
 */
int getIdJogador(Jogador j);

/**
 * Função que recebe um jogador e imprime suas informações conforme o formato
 * especificado.
 *
 * @param j Jogador.
 */
void printaJogador(Jogador j);

#endif
