#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno {
    char *nome; // Ponteiro para nome do aluno, que será alocado dinamicamente
    int matricula; // Matrícula do aluno
    int n1, n2, n3; // Notas das avaliações
} tAluno;

/**
 * @brief Cria um novo aluno vazio. Os atributos inteiros devem receber
 *        valor -1, e o ponteiro do nome deve apontar para NULL.
 *
 * @return Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno *CriaAluno(void);

/**
 * @brief Função para liberar toda a memória alocada dinamicamente para
 *        estrututas do tipo tAluno.
 *
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno);

/**
 * @brief Lê os dados de um aluno.
 *
 * @param aluno Ponteiro para aluno (alocado dinamicamente), cujos dados serão
 *              preenchidos nessa função.
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Compara as matrículas de dois alunos.
 *
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a
 *         matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são
 *         iguais.
 */
int ComparaMatricula(tAluno *aluno1, tAluno *aluno2);

/**
 * @brief Calcula a média das notas de um aluno.
 *
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno *aluno);

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 *
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno *aluno);

/**
 * @brief Imprime os dados de um aluno.
 *
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno *aluno);

#endif
