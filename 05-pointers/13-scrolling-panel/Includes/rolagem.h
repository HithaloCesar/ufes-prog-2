#ifndef ROLAGEM_H
#define ROLAGEM_H

#define TAM_MAX_MSG 1000
#define NUM_MAX_MSGS 10

/**
 * @brief Ponteiro para função (callback)
 *
 * @param msg Array de mensagens (parâmetro de saída).
 * @param numMsgs Número de mensagens (parâmetro de saída).
 * @param dadosUsuario Ponteiro "genérico" para os dados do usuário.
 */
typedef void (*FptrMsg)(
    char msg[NUM_MAX_MSGS][TAM_MAX_MSG],
    int *numMsgs,
    void *dadosUsuario
);

/**
 * @brief Dispara a função de rolagem de mensagens
 *
 * @param FuncMsg Ponteiro para a função de callback.
 * @param tamanhoDisplay Tamanho do display.
 * @param tempoFim Tempo de duração da rolagem.
 * @param dadosUsuario Um ponteiro fornecido pelo usuário (main) que será
 *                     repassado para o callback 'FuncMsg'.
 */
void RolaMsg(
    FptrMsg FuncMsg,
    int tamanhoDisplay,
    int tempoFim,
    void *dadosUsuario
);

#endif
