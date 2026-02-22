#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define TAM_STRING 100

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} 

int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    do {

        printf("======================================\n");
        printf("       BIBLIOTECA - PARTE 1\n");
        printf("======================================\n");
        printf("1. Cadastrar novo Livro\n");
        printf("2. Listar todos os livros\n");
        printf("0. Sair\n");
        printf("--------------------------------------\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o buffer de entrada após ler a opção

        switch (opcao) {
            case 1:
                printf("--- Cadastro de Novo Livro: ---\n\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                    
                    printf("Digite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada(); // Limpa o buffer de entrada após ler a edição

                    totalLivros++;
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Capacidade máxima de livros atingida!\n");
                }
                break;

            case 2:
                if (totalLivros > 0) {
                    printf("\nLista de Livros:\n");
                    for (int i = 0; i < totalLivros; i++) {
                        printf("Livro %d:\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edição: %d\n", biblioteca[i].edicao);
                        printf("--------------------------------------\n");
                    }
                } else {
                    printf("Nenhum livro cadastrado!\n");
                }
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }