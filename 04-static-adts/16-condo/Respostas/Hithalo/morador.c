#include "morador.h"
#include <stdio.h>
#include <string.h>

Morador lerMorador() {
    Morador m;
    scanf(" %[^\n]\n", m.nome);
    scanf(" %[^\n]\n", m.cpf);
    m.dataNasc = lerData();
    scanf(" %[^\n]\n", m.idResidencia);

    return m;
}

void imprimeMorador(Morador m) {
    printf("Nome: %s\n", m.nome);
    printf("CPF: %s\n", m.cpf);
    printf("Data de Nascimento: ");
    imprimeData(m.dataNasc);
    printf("Residencia: %s\n", m.idResidencia);
}

int comparaMorador(Morador m1, Morador m2) {
    return !strcmp(m1.cpf, m2.cpf);
}

int verificaCPFMorador(Morador m1, char *cpf) {
    return !strcmp(m1.cpf, cpf);
}

int calculaIdadeMorador(Morador m, Data dataRef) {
    return calcularDiffAnosData(m.dataNasc, dataRef);
}
