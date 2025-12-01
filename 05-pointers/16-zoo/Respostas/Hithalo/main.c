#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tZoologico.h"

typedef enum {
    OPERACAO_ADICIONAR_ANIMAL = 'A',
    OPERACAO_PASSAR_DIA = 'D',
    OPERACAO_REGISTRAR_FUGA = 'F',
    OPERACAO_ENCERRAR = 'E'
} tOperacao;

static void ImprimeMenu(tZoologico *z);

int main(void) {
    char buffer[MAX_TAMANHO_NOME];
    scanf("%[^\n]", buffer);

    int nRecintos, capacidade;
    scanf("%d %d", &nRecintos, &capacidade);

    tZoologico z = CriaZoologico(buffer, nRecintos, capacidade);

    bool execucao = true;
    while (execucao) {
        ImprimeMenu(&z);

        char op;
        scanf(" %c", &op);

        switch (op) {
            case OPERACAO_ADICIONAR_ANIMAL: {
                printf("Informe o nível de fome e o nome do animal:\n");

                if (ZoologicoLotado(&z)) {
                    printf("FUGA GERAL NO ZOOLÓGICO!!!\n");
                    printf("Todos os animais fugiram.\n");

                    execucao = false;
                    break;
                }

                int fome;
                scanf("%d %[^\n]", &fome, buffer);
                AdicionaAnimalZoologico(&z, CriaAnimal(buffer, fome));
                break;
            }

            case OPERACAO_PASSAR_DIA: {
                PassaDiaZoologico(&z);
                break;
            }

            case OPERACAO_REGISTRAR_FUGA: {
                printf("Informe o recinto em que ocorreu a fuga:\n");
                int idx;
                scanf("%d", &idx);
                FugaRecintoZoologico(&z, idx);
                break;
            }

            case OPERACAO_ENCERRAR: {
                EncerraZoologico(&z);
                execucao = false;
                break;
            }

            default: {
                fprintf(stderr, "ERRO: Input inválido.\n");
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}

static void ImprimeMenu(tZoologico *z) {
    printf("Dia %d no zoológico %s\n", GetDia(z), GetNome(z));
    printf("Menu:\n");
    printf(" A - Adicionar animal\n");
    printf(" D - Passar o dia\n");
    printf(" F - Registrar fuga em recinto\n");
    printf(" E - Encerrar programa\n");
}
