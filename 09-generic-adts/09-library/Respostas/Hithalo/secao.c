#include "secao.h"
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_ARRAY_SIZE 4

struct Secao {
    void **dados;
    int size;
    int len;
    func_ptr_desaloca_item desaloca;
};

Secao *criarSecao(func_ptr_desaloca_item desaloca) {
    Secao *sec = calloc(1, sizeof(*sec));

    sec->desaloca = desaloca;

    return sec;
}

void addItemSecao(Secao *sec, void *item) {
    if (sec->len == sec->size) {
        if (sec->size == 0) {
            sec->size = DEFAULT_ARRAY_SIZE;
        } else {
            sec->size *= 2;
        }
        sec->dados = realloc(sec->dados, sec->size * sizeof(sec->dados));
    }

    sec->dados[sec->len++] = item;
}

void imprimirItensSecao(Secao *sec, func_ptr_imprime_item imprime) {
    for (int i = 0; i < sec->len; i++) {
        imprime(sec->dados[i]);
    }
}

void imprimirItensPorChaveSecao(
    Secao *sec,
    void *chave,
    func_ptr_comparar_item compara,
    func_ptr_imprime_item imprime
) {
    for (int i = 0; i < sec->len; i++) {
        if (compara(sec->dados[i], chave)) {
            imprime(sec->dados[i]);
        }
    }
}

void desalocarSecao(Secao *sec) {
    for (int i = 0; i < sec->len; i++) {
        sec->desaloca(sec->dados[i]);
    }
    free(sec->dados);
    free(sec);
}
