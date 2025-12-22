#ifndef _TICKET_H
#define _TICKET_H

#define MAXNOMETICKET 50
#define MAXDESCRICAOTICKET 200
#define MAXSITUACAOTICKET 12

typedef struct tic_str tTicket;

/** @brief aloca a memória de um tipo tTicket e o inicializa com
 * os parametros passados, retornando o ponteiro alocado.
 * @param nome titulo do ticket
 * @param codigo codigo de identificacao do ticket
 * @param descricao descricao do ticket
 * A situação do ticket deve ser iniciada como "PENDENTE"
 */
tTicket* criaTicket(char* nome, int codigo, char *descricao);

/** @brief lê as informacoes do ticket e retorna seu ponteiro alocado
 * Lembre-se de cria-lo utilizando a funcao criaTicket e utilize a seguinte formatacao
 * nome
 * codigo
 * descricao
 */
tTicket* leTicket();

/** @brief altera a situacao do ticket para "CONCLUIDO"
 */
void alteraSituacaoTicket(tTicket *t);

/** @brief compara se o código passado por parâmetro corresponde ao
 * código de identificação de um ticket
 * Retorna 1 se verdadeiro e 0 se falso.
 * 
 */
int comparaTicket(tTicket *t, int codigo);

/** @brief função get que retonar o nome do ticket
 */
char *retornaNomeTicket(tTicket *t);

/** @brief retorna 1 se o ticket ainda esta pendente, 0 caso contrario */
int estaPendenteTicket(tTicket *t);

/** @brief imprime as informações de um ticket a partir da seguinte formatação:
 * ======================
 * Nome: Resistor queimado
 * Codigo: 1225
 * Situacao: PENDENTE
 * Descricao: Resistor de 190 Ohms de um circuito impresso está queimado e precisa de substituicao
 */

void imprimeTicket(tTicket *t);


/** @brief libera a memória alocada para o ticket
 */
void destroiTicket(tTicket *t);

#endif