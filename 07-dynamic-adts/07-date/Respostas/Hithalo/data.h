#ifndef DATA_H
#define DATA_H

typedef struct Data {
    int dia;
    int mes;
    int ano;
} tData;

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna.
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 *
 * @return Data "vazia".
 */
tData *CriaData(void);

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada
 *        dinamicamente.
 *
 * @param d Ponteiro para a estrutura onde os dados serão armazenados.
 *             Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData *d);

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo
 *        tData, passada como parâmetro
 * @param d Ponteiro para a estrutura onde os dados estão armazenados.
 */
void LiberaData(tData *d);

/**
 * @brief Verifica se uma data é válida.
 *
 * @param d Data a ser verificada.
 * @return 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData *d);

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param d Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData *d);

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param d Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData *d);

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param d Data cujo ano será verificado.
 * @return 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData *d);

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param d Data cujo mês terá o número de dias retornado.
 * @return Número de dias do mês da data.
 */
int NumeroDiasMes(tData *d);

/**
 * @brief Compara duas datas.
 *
 * @param d1 Primeira data a ser comparada.
 * @param d2 Segunda data a ser comparada.
 * @return 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as
 *         datas são iguais.
 *         A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData *d1, tData *d2);

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param d Data cujo número de dias até o início do mês será calculado.
 * @return Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData *d);

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param d1 Primeira data a ser comparada.
 * @param d2 Segunda data a ser comparada.
 * @return Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData *d1, tData *d2);

#endif
