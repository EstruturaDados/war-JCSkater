#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100

// definição da estrutura struct
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// Função para limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} 

// função principal (main)
int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

// laço principal do menu
    do {
        // exibe o menu de opções.
        printf("======================================\n");
        printf("       BIBLIOTECA - PARTE 1\n");
        printf("======================================\n");
        printf("1. Cadastrar novo Livro\n");
        printf("2. Listar todos os livros\n");
        printf("0. Sair\n");
        printf("--------------------------------------\n");
        printf("Escolha uma opção: ");

        // lê a opção do usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf.

        // processamento da opção
        switch (opcao) {
            case 1: // Cadastro de livro
                printf("--- Cadastro de Novo Livro: ---\n\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                    
                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';                    
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada(); // Limpa o buffer de entrada após ler a edição

                    totalLivros++;

                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu.
                break;

            case 2: // listagem de livros
                printf("--- Lista de Livros Cadastrados ---\n\n");

                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                        printf("--------------------------------------\n");
                        printf("Livro %d:\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edição: %d\n", biblioteca[i].edicao);
                    }
                    printf("--------------------------------------\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu.
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu.
                break;
        }
    } while (opcao != 0);

        return 0; // Fim do programa
    }