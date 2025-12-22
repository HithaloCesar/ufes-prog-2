#include "usuario.h"
#include <stdlib.h>
#include <stdio.h>

tUsuario *CriaUsuario(void) {
    tUsuario *user = calloc(1, sizeof(*user));

    return user;
}

void DestroiUsuario(tUsuario *user) {
    free(user);
}

void LeUsuario(tUsuario *user) {
    scanf(" %s %s", user->nome, user->cpf);
    getchar();
}

void ImprimeUsuario(tUsuario *user) {
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}
