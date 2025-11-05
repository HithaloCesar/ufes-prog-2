#ifndef ESFERA_UTILS_H
#define ESFERA_UTILS_H

#define PI 3.14

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param volume Um ponteiro para uma variável float para armazenar o volume
 *               calculado.
 */
void CalculaVolume (float R, float *volume);

/**
 * @brief Calcula a área de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param area Um ponteiro para uma variável float para armazenar a área
 *             calculada.
 */
void CalculaArea (float R, float *area);

#endif
