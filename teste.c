#include <stdio.h>
#include <string.h>

#define QTD_TERRITORIOS 5
#define TAM_NOME 50
#define TAM_COR 20

typedef struct {
    char nome[TAM_NOME];
    char corExercito[TAM_COR];
    int numTropas;
} Territorio;

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int main() {
    Territorio territorios[QTD_TERRITORIOS];

    printf("Cadastro dos Territórios:\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\n Cadastrando Território %d:\n", i+1);

        printf("Nome do Território: ");
        fgets(territorios[i].nome, TAM_NOME, stdin);
        removerNovaLinha(territorios[i].nome);

        printf("Cor do Exército: ");
        fgets(territorios[i].corExercito, TAM_COR, stdin);
        removerNovaLinha(territorios[i].corExercito);

        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].numTropas);
        getchar(); // Limpa o '\n' deixado pelo scanf
    }

    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Território %d:\n", i+1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Dominado por: %s\n", territorios[i].corExercito);
        printf("  Tropas: %d\n", territorios[i].numTropas);
        printf("-----------------------------\n");
    }

    return 0;
}