#include <stdio.h>
#include <stdlib.h>



// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define LINHAS 10
#define COLUNAS 10

// Função para inicializar tabuleiro com zeros
void inicializaTabuleiro(int tab[LINHAS][COLUNAS]) 
{
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            tab[i][j] = 0;
}

// Função para posicionar navios (tamanho 3, 2 verticais/horizontais, 2 diagonais)
int posicionaNavios(int tab[LINHAS][COLUNAS]) 
{
    // Dois navios horizontais/verticais (simples, sem validação pesada)
    int navios[4][2] = 
    {
        {2, 4}, // navio horizontal na linha 2, coluna 4
        {5, 7}, // navio vertical na linha 5, coluna 7
        {0, 0}, // diagonal descendo
        {9, 9}  // diagonal subindo
    };

    // Navio 1 horizontal (linha 2, col 4..6)
    for (int i = 0; i < 3; i++) 
    {
        tab[navios[0][0]][navios[0][1] + i] = 3;
    }

    // Navio 2 vertical (linha 5..7, col 7)
    for (int i = 0; i < 3; i++) 
    {
        tab[navios[1][0] + i][navios[1][1]] = 3;
    }

    // Navio 3 diagonal descendente (linha,col aumentam)
    for (int i = 0; i < 3; i++) 
    {
        tab[navios[2][0] + i][navios[2][1] + i] = 3;
    }

    // Navio 4 diagonal ascendente (linha diminui, col aumenta)
    for (int i = 0; i < 3; i++) 
    {
        tab[navios[3][0] - i][navios[3][1] - i] = 3;
    }

    return 0;
}

// Função para criar a matriz da habilidade Cone (5x5)
void criaCone(int cone[5][5]) 
{
    // Cone apontando para baixo, base maior na parte inferior
    // Usaremos uma lógica simples: a linha determina o "raio" da cone

    for (int i = 0; i < 5; i++) 
    {
        int raio = i; // aumenta para baixo
        for (int j = 0; j < 5; j++) 
        {
            // posição central é coluna 2 (0-based)
            if (j >= 2 - raio && j <= 2 + raio)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para criar a matriz da habilidade Cruz (5x5)
void criaCruz(int cruz[5][5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            if (i == 2 || j == 2) // linha e coluna centrais formam cruz
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para criar a matriz da habilidade Octaedro (5x5)
void criaOctaedro(int octaedro[5][5]) 
{
    // Forma de losango
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            // distância manhattan do centro (2,2)
            int dist = abs(i - 2) + abs(j - 2);
            if (dist <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

// Função para aplicar uma habilidade no tabuleiro
void aplicaHabilidade(int tab[LINHAS][COLUNAS], int hab[5][5], int origemLinha, int origemColuna) 
{
    int meio = 2; // meio da matriz 5x5

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            if (hab[i][j] == 1) 
            {
                int linTab = origemLinha + (i - meio);
                int colTab = origemColuna + (j - meio);

                // Verifica limites do tabuleiro
                if (linTab >= 0 && linTab < LINHAS && colTab >= 0 && colTab < COLUNAS) 
                {
                    // Se não for navio (3), marca habilidade com 5
                    if (tab[linTab][colTab] == 0) 
                    {
                        tab[linTab][colTab] = 5;
                    }
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro formatado
void imprimeTabuleiro(int tab[LINHAS][COLUNAS]) 
{
    printf("    A  B  C  D  E  F  G  H  I  J\n");
    for (int i = 0; i < LINHAS; i++) 
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) 
        {
            if (tab[i][j] == 0)
                printf(" . "); // água (ponto para visual ficar mais limpo)
            else 
                if (tab[i][j] == 3)
                    printf(" N "); // navio
            else 
                if (tab[i][j] == 5)
                    printf(" * "); // área de habilidade
            else
                printf(" ? "); // valor desconhecido
        }
        printf("\n");
    }
}

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


int tabuleiro[LINHAS][COLUNAS];    
    int cone[5][5], cruz[5][5], octaedro[5][5];

    inicializaTabuleiro(tabuleiro);
    posicionaNavios(tabuleiro);

    criaCone(cone);
    criaCruz(cruz);
    criaOctaedro(octaedro);

    // Define pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 3, origemConeColuna = 3;
    int origemCruzLinha = 7, origemCruzColuna = 7;
    int origemOctaedroLinha = 5, origemOctaedroColuna = 2;

    aplicaHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicaHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicaHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    imprimeTabuleiro(tabuleiro);

    return 0;
}
