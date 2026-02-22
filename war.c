// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h>
// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define QTD_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10
// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
};

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // Vetor estático para armazenar 5 territórios
    struct Territorio territorios[QTD_TERRITORIOS];

    printf("=====================================\n");
    printf("      SISTEMA DE TERRITORIOS\n");
    printf("=====================================\n\n");

    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");
    // Laço para cadastro dos 5 territórios
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\n --- Cadastrando Territorio %d ---\n", i+1);
        
        // Leitura do nome do território
        printf("Nome do Território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        // Remove o '\n' que o fgets adiciona
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; 

        // Leitura da cor do exército
        printf("Cor do Exercito (ex: Azul, Verde): ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        
        // Remove o '\n' do final da string
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; 

        // Leitura do número de tropas
        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);

        // Limpeza do buffer após scanf
        getchar(); 
    
    }
    
    printf("\n");
    printf("Cadastro Inicial concluido com sucesso!\n");

    // Exibição dos dados cadastrados
    printf("\n=====================================\n");
    printf("      MAPA DO MUNDO - ESTADO ATUAL     \n");
    printf("=======================================\n");

    for (int i = 0; i < 5; i++) {
        printf("\nTERRITORIO %d\n", i + 1);
        printf("- Nome: %s\n", territorios[i].nome);
        printf("- Dominado por: Exercito %s\n", territorios[i].cor);
        printf("- Tropas: %d\n", territorios[i].tropas);
    }
    printf("\n");
    return 0; // Finaliza o programa com sucesso
}
