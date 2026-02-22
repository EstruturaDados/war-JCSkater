#include <stdio.h>
#include <string.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio territorios[5];
int i;          
    for (i = 0; i < 5; i++) {
        printf("Digite o nome do território %d: ", i + 1);
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Remove o '\n' do final da string

        printf("Digite a cor do território %d: ", i + 1);
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; // Remove o '\n' do final da string

        printf("Digite o número de tropas no território %d: ", i + 1);
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada(); // Limpa o buffer de entrada após ler o número
    }

    printf("\nTerritórios cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}