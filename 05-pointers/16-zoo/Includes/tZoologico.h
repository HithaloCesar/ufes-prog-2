#ifndef TZOOLOGICO_H
#define TZOOLOGICO_H
#include "tRecinto.h"

#define MAX_TAMANHO_NOME 50
#define MAX_RECINTOS 10

/**
 * @brief Tipo que representa um zoológico.
 *
 * Contém um nome, um conjunto fixo de recintos e informações sobre capacidade
 * total.
 * O gerenciamento é feito de forma estática, sem uso de alocação dinâmica.
 */
typedef struct {
    char nome[MAX_TAMANHO_NOME]; // Nome do zoológico
    tRecinto recintos[MAX_RECINTOS]; // Vetor fixo de recintos
    int nRecintos; // Quantidade de recintos existentes
    int capacidade; // Capacidade de cada recinto
    int dia; // Contador de dias no zoológico
} tZoologico;

/**
 * @brief Cria e retorna um zoológico inicializado com os parâmetros
 *        fornecidos.
 *
 * Cada recinto é criado chamando CriaRecinto(capacidade).
 * O contador de dias começa em 0.
 *
 * @param nome Nome do zoológico.
 * @param nRecintos Número de recintos do zoológico (máx. 10).
 * @param capacidade Capacidade máxima de animais em cada recinto.
 * @return Estrutura tZoologico inicializada.
 */
tZoologico CriaZoologico(char *nome, int nRecintos, int capacidade);

/**
 * @brief Tenta adicionar um animal em um dos recintos do zoológico.
 *
 * O animal é adicionado no primeiro recinto disponível (não lotado).
 * Caso todos os recintos estejam cheios, retorna 0.
 *
 * @param z Ponteiro para o zoológico.
 * @param a Animal a ser adicionado (passado por valor).
 * @return 1 se o animal foi adicionado com sucesso, 0 se o zoológico estiver
 *         lotado.
 */
int AdicionaAnimalZoologico(tZoologico *z, tAnimal a);

/**
 * @brief Avança o dia em todos os recintos do zoológico.
 *
 * Todos os animais aumentam seu nível de fome e, se morrerem,
 * suas mortes são registradas. O contador de dias é incrementado.
 *
 * @param z Ponteiro para o zoológico.
 */
void PassaDiaZoologico(tZoologico *z);

/**
 * @brief Registra uma fuga em um recinto específico.
 *
 * Caso o índice informado seja inválido, imprime "Valor invalido".
 *
 * @param z Ponteiro para o zoológico.
 * @param idx Índice do recinto onde ocorreu a fuga.
 */
void FugaRecintoZoologico(tZoologico *z, int idx);

/**
 * @brief Encerra o zoológico.
 *
 * Se ainda houver animais, imprime:
 * "Animais liberados para a finalizacao do programa!!!"
 * Caso contrário, imprime:
 * "Programa finalizado com sucesso."
 *
 * @param z Ponteiro para o zoológico.
 */
void EncerraZoologico(tZoologico *z);

/**
 * @brief Verifica se todos os recintos do zoológico estão lotados.
 *
 * @param z Ponteiro para o zoológico.
 * @return 1 se todos estiverem lotados, 0 caso contrário.
 */
int ZoologicoLotado(tZoologico *z);

/**
 * @brief Retorna o nome do zoológico.
 *
 * @param z Ponteiro para o zoológico.
 * @return Ponteiro para string com o nome do zoológico.
 */
char *GetNome(tZoologico *z);

#endif
