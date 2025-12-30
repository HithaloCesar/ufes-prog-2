#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "movel.h"
#include "fila.h"

#define STRING_MAX_LEN 8

int main(void) {
    Fila *f = FilaConstruct();

    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);

    for (int i = 0; i < qtdOperacoes; i++) {
        char string[STRING_MAX_LEN + 1];
        scanf(" %s", string);

        if (!strcmp(string, "ENTRADA")) {
            tMovel *m = LeMovel();
            FilaPush(f, m);
        } else if (!strcmp(string, "PRODUZIR")) {
            tMovel *m = FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }

    FilaDestroy(f, DestroiMovel);

    return EXIT_SUCCESS;
}
