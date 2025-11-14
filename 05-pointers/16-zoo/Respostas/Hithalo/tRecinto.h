#ifndef TRECINTO_H
#define TRECINTO_H
#include "tAnimal.h"

#define MAX_ANIMAIS_RECINTO 20

/**
 * @brief Tipo que representa um recinto dentro do zoológico.
 *
 * Armazena até um número fixo de animais, determinado pela capacidade.
 * O gerenciamento dos animais é feito de forma estática (sem alocação
 * dinâmica).
 */
typedef struct {
    tAnimal animais[MAX_ANIMAIS_RECINTO]; // Vetor fixo de animais no recinto
    int capacidade; // Quantidade máxima de animais que o recinto comporta
    int qtd; // Quantidade atual de animais no recinto
} tRecinto;

/**
 * @brief Cria e retorna um novo recinto com capacidade definida.
 *
 * Inicializa a quantidade de animais como 0.
 *
 * @param capacidade Capacidade máxima de animais que o recinto comporta.
 * @return Estrutura tRecinto inicializada.
 */
tRecinto CriaRecinto(int capacidade);

/**
 * @brief Adiciona um animal ao recinto, se houver espaço disponível.
 *
 * A função adiciona o animal na primeira posição livre.
 *
 * @param r Ponteiro para o recinto onde o animal será adicionado.
 * @param a Animal a ser adicionado (passado por valor).
 * @return 1 se o animal foi adicionado com sucesso, 0 caso o recinto esteja
 *         lotado.
 */
int AdicionaAnimalRecinto(tRecinto *r, tAnimal a);

/**
 * @brief Simula a passagem de um dia para todos os animais do recinto.
 *
 * Todos os animais têm seu nível de fome incrementado.
 * Caso algum morra (fome >= 10), é removido e sua morte é impressa.
 *
 * @param r Ponteiro para o recinto.
 */
void PassaDiaRecinto(tRecinto *r);

/**
 * @brief Registra uma fuga de todos os animais do recinto.
 *
 * Todos os animais são "liberados" e a contagem do recinto é zerada.
 *
 * @param r Ponteiro para o recinto.
 */
void FugaRecinto(tRecinto *r);

/**
 * @brief Verifica se o recinto está lotado.
 *
 * @param r Ponteiro para o recinto.
 * @return 1 se o recinto estiver cheio, 0 caso contrário.
 */
int EstaLotadoRecinto(tRecinto *r);

/**
 * @brief Verifica se o recinto está vazio.
 *
 * @param r Ponteiro para o recinto.
 * @return 1 se o recinto estiver vazio, 0 caso contrário.
 */
int EstaVazioRecinto(tRecinto *r);

#endif
