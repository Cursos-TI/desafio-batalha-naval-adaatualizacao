#include <stdio.h>



// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define LINHAS 10
#define COLUNAS 10

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


        // Definindo o tabuleiro 10x10, inicialmente com valor 0 (água)
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // Posicionamento dos navios
    // Horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Vertical
    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Diagonal principal (top-left para bottom-right)
    int linha_diagonal1 = 1;
    int coluna_diagonal1 = 1;

    // Diagonal secundária (top-right para bottom-left)
    int linha_diagonal2 = 3;
    int coluna_diagonal2 = 7;

    // Posicionar o navio horizontal
    for (int i = 0; i < 3; i++) 
    {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posicionar o navio vertical
    for (int i = 0; i < 3; i++) 
    {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Posicionar o navio diagonal 1 (top-left para bottom-right)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = 3;
    }

    // Posicionar o navio diagonal 2 (top-right para bottom-left)
    for (int i = 0; i < 3; i++) 
    {
        tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = 3;
    }

    // Exibir o tabuleiro com as letras de A a J para as colunas
    printf("    A  B  C  D  E  F  G  H  I  J\n");

    // Exibir as linhas do tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1); // Número da linha

        for (int j = 0; j < COLUNAS; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}
