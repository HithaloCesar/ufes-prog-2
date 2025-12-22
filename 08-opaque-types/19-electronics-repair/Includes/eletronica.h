#ifndef _ELETRONICA_H
#define _ELETRONICA_H

#include "ticket.h"
#include "tecnico.h"

#define QTDMAXTECNICO 10
#define QTDMAXNOMEELETRONICA 50

typedef struct str_ele tEletronica;

/** @brief cria, alocando na memoria, um tipo tEletronica, a partir dos parametros
 * Uma eletronica tem um nome (char *), um vetor de ponteiros para tecnicos (Tecnicos **)
 * e um qtdTecnicos, que se inicia com 0;
 * aloque 10 espacos para o vetor tTecnico e inicie qtdTecnicos como 0
 * @return um tipo tEletronica inicializado e alocado
 */
tEletronica *criaEletronica(char *nome);

/** @brief adiciona um tipo tTecnico na lista de tecnicos de uma eletronica
 * @param e eletronica a ter um tecnico adicionado
 * @param t tecnico a ser adicionado
 */
void cadastraTecnico(tEletronica *e, tTecnico *t);

/** @brief adiciona um ticket a um tecnico pertencente a uma eletronica
 * utilize o id para pesquisar e encontrar o tecnico com codigo de identificao igual
 * caso nao encontre, imprima a mensagem de erro "TECNICO NAO ENCONTRADO" e não faça nada
 * @param e eletronica a ter a lista de tecnicos pesquisada
 * @param id codigo de identificacao do tecnico a ter o ticket atribuido
 * @param t ticket a ser atribuido
 */
void atribuiTicketEletronica(tEletronica *e, char *id, tTicket *t);

/** @brief dobra a qtdMaxTickets de um tecnico, utilizando o id como parametro de pesquisa
 * caso nao encontre, imprima a mensagem de erro "TECNICO NAO ENCONTRADO" e não faça nada
 * @param e eletronica a ter a lista de tecnicos pesquisada
 * @param id codigo de identificacao do tecnico a ter a carga aumentada
*/ 
void aumentaCargaTecnicoEletronica(tEletronica *e, char *id);


/** @brief encontra um ticket na lista de ticket de todos os tecnicos de uma eletronica,
 * utilizando o codigo para pesquisa, e altera sua situacao para "CONCLUIDO"
 * @param e eletronica a ser pesquisada
 * @param codigo codigo a ser utilizado para pesquisar o ticket
 */
void alteraSituacaoTicketEletronica(tEletronica *e, int codigo);

/** @brief imprime as informacoes de uma eletronica a partir da seguinte formatacao
 * Nome: WS Eletronica
 * Tecnicos empregados:
 * Ficha do Tecnico #####
 * Nome: Ronaldo
 * Id: SUP0024
 * Tickets atribuidos:
 * ======================
 * Nome: Resistor queimado
 * Codigo: 1225
 * Situacao: PENDENTE
 * Descricao: Resistor de 190 Ohms de um circuito impresso está queimado e precisa de substituicao
 * ======================
 * Tecnico com maior numero de pendencias: Ronaldo, 1 pendencia(s)
 */
void imprimeEletronica(tEletronica *e);

/** @brief desaloca toda a memoria alocada para um tipo tEletronica
 * 
 */
void destroiEletronica(tEletronica *e);

#endif