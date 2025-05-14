#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

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


    // Definindo o tamanho do tabuleiro e do navio diretamente no código
    int tabuleiro[10][10] = {0};  // Tabuleiro 10x10 inicializado com 0 (água)

    // Posições dos navios
    int linha_horizontal = 2;  // Linha do navio horizontal
    int coluna_horizontal = 4; // Coluna do navio horizontal

    int linha_vertical = 5;    // Linha do navio vertical
    int coluna_vertical = 7;  // Coluna do navio vertical

    // Posicionar o navio horizontal. O navio horizontal tem 3 partes
    for (int i = 0; i < 3; i++) 
    {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;  // Coloca "3" no tabuleiro
    }

    // Posicionar o navio vertical. O navio vertical também tem 3 partes
    for (int i = 0; i < 3; i++) 
    {  
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;  // Coloca "3" no tabuleiro
    }

    // Exibir o tabuleiro com as letras de A a J para as colunas
    printf("    A  B  C  D  E  F  G  H  I  J\n");

    for (int i = 0; i < 10; i++) 
    {
        // Imprimir o número da linha à esquerda
        printf("%2d ", i + 1);

            // Imprimir cada elemento do tabuleiro
            for (int j = 0; j < 10; j++) 
            {
                printf("%2d ", tabuleiro[i][j]);
            }
        printf("\n");
    }

    return 0;
}
