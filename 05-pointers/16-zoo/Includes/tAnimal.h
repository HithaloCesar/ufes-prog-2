#ifndef TANIMAL_H
#define TANIMAL_H

#define MAX_TAMANHO_NOME 50

/**
 * @brief Tipo que representa um animal no zoológico.
 *
 * Contém informações sobre o nome e o nível de fome.
 * Não usa alocação dinâmica: os dados são armazenados diretamente na
 * estrutura.
 */
typedef struct {
    char nome[MAX_TAMANHO_NOME];
    int fome;
} tAnimal;

/**
 * @brief Inicializa e retorna um novo animal.
 *
 * Cria um animal a partir dos parâmetros fornecidos.
 * Caso o valor de fome seja menor ou igual a 0, o programa
 * imprime "VALOR INVALIDO", define o nome do animal como "Desconhecido" e a
 * fome como 0.
 *
 * @param nome Nome do animal.
 * @param fome Nível inicial de fome (deve ser maior que 0).
 * @return tAnimal inicializado com os valores válidos (ou padrão, em caso de
 *         erro).
 */
tAnimal CriaAnimal(char *nome, int fome);

/**
 * @brief Incrementa em 1 o nível de fome do animal.
 *
 * Essa função simula a passagem de um dia no zoológico.
 *
 * @param a Ponteiro para o animal que terá o nível de fome incrementado.
 */
void PassaDiaAnimal(tAnimal *a);

/**
 * @brief Verifica se o animal morreu de fome.
 *
 * Um animal é considerado morto se sua fome for maior ou igual a 10.
 *
 * @param a Ponteiro para o animal a ser verificado.
 * @return 1 se o animal morreu de fome, 0 caso contrário.
 */
int AnimalEstaMorto(tAnimal *a);

/**
 * @brief Exibe a mensagem de fuga do animal.
 *
 * O formato da mensagem é: "Animal <nome> fugiu!"
 *
 * @param a Ponteiro para o animal que fugiu.
 */
void ImprimeFugaAnimal(tAnimal *a);

/**
 * @brief Exibe a mensagem de morte do animal.
 *
 * O formato da mensagem é: "Animal <nome> morreu de fome.".
 *
 * @param a Ponteiro para o animal que morreu.
 */
void ImprimeMorteAnimal(tAnimal *a);

/**
 * @brief Retorna o nome do animal.
 *
 * @param a Ponteiro para o animal cujo nome será retornado.
 * @return Ponteiro para a string com o nome do animal.
 */
char *NomeAnimal(tAnimal *a);

#endif
