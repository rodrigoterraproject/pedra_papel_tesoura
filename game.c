#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para obter a escolha do jogador
int get_player_choice() {
    int choice;
    printf("Escolha:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("Digite o número correspondente: ");
    scanf("%d", &choice);

    return choice;
}

// Função para obter a escolha aleatória do computador
int get_computer_choice() {
    return (rand() % 3) + 1; // Gera um número aleatório entre 1 e 3
}

// Função para determinar o vencedor
void determine_winner(int player, int computer) {
    printf("Você escolheu: %d\n", player);
    printf("O computador escolheu: %d\n", computer);

    if (player == computer) {
        printf("Empate!\n");
    } else if ((player == 1 && computer == 3) || 
               (player == 2 && computer == 1) || 
               (player == 3 && computer == 2)) {
        printf("Você venceu!\n");
    } else {
        printf("O computador venceu!\n");
    }
}

int main() {
    int player_choice, computer_choice;

    // Inicializa a semente para números aleatórios
    srand(time(NULL));

    printf("Bem-vindo ao jogo Pedra, Papel e Tesoura!\n");

    do {
        player_choice = get_player_choice();
        computer_choice = get_computer_choice();
        determine_winner(player_choice, computer_choice);

        // Pergunta se o jogador quer jogar novamente
        printf("\nDeseja jogar novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &player_choice);
        printf("\n");

    } while (player_choice != 0);

    printf("Obrigado por jogar!\n");

    return 0;
}
