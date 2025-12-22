#ifndef USUARIO_H
#define USUARIO_H

#define TAM_MAX_NOME 50
#define TAM_MAX_CPF 15

typedef struct Usuario {
    char nome[TAM_MAX_NOME]; // Nome do usuário.
    char cpf[TAM_MAX_CPF]; // CPF do usuário.
} tUsuario;

/**
 * @brief Cria um novo usuário.
 *        Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario(void);

/**
 * @brief Desaloca a memória de um usuário.
 *
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user);

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 *
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user);

/**
 * @brief Imprime os dados de um usuário.
 *
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user);

#endif
