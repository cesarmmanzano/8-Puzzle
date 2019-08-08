/*
Puzzle 8
Pontifícia Universidade Católica de Campinas
Cesar Marrote Manzano
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "menu.h"
#include "game.h"
#include "solution.h"

//Funções do programa main
void mudacor(int cor);
void gotoxy(int linha, int coluna);
void imprime_grade(int linha_inicial, int col_inicial);
void numeros_grade_inicio(char matriz_grade[][3]);
void numeros_grade_objetivo(char matriz_grade[][3]);

void main()
{
    int coluna_num, linha_num;

    int escolha_jogo;

    int joga_denovo;

    do
    {

//Matrizes que serão usadas no jogo
//1 matriz de objetivo
//2 matrizes para jogos diferentes

        char matriz_objetivo[3][3] = { { '1', '2', '3' },
            { '4', '5', '6' },
            { '7', '8', ' ' }
        };

        char matriz_inicio[3][3] = { { '4', '1', '3' },
            { '2', '8', '5' },
            { '7', ' ', '6' }
        };

        char matriz_inicio2[3][3] = { { '4', '1', '3' },
            { '2', ' ', '6' },
            { '7', '5', '8' }
        };



        /************************************************************************/


//Início do programa

        menu(&escolha_jogo, matriz_objetivo);

        jogo(matriz_inicio, matriz_inicio2, matriz_objetivo, escolha_jogo);

        system("cls");
        parabens_texto();

        mudacor(15);
        printf("\n\nVoce deseja jogar novamente?<0-Nao><1-Sim>");
        scanf("%d", &joga_denovo);
    }
    while(joga_denovo == 1);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
}


//Função que muda a cor
void mudacor(int cor)
{

    /*
    Lista de cores:
    0 = Preto		8 = Cinza
    1 = Azul		9 = Azul Claro
    2 = Verde		10 = Verde Claro
    3 = Verde-Agua	11 = Verde-Agua Claro
    4 = Vermelho	12 = Vermelho Claro
    5 = Roxo		13 = Lilas
    6 = Amarelo		14 = Amarelo Claro
    7 = Branco		15 = Branco Brilhante
    */

    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida,cor);
}


//Move o cursor para a linha y e coluna x
void gotoxy(int linha, int coluna)
{
    HANDLE Saida;
    COORD Posicao;

    Saida = GetStdHandle(STD_OUTPUT_HANDLE);

    Posicao.X = coluna;
    Posicao.Y = linha;

    SetConsoleCursorPosition(Saida, Posicao);
}


//Desenha grade para o jogo
void imprime_grade(int linha_inicial, int coluna_inicial)
{
    int linha = linha_inicial;
    int coluna = coluna_inicial;

    gotoxy(coluna, linha);
    printf("\332\304\304\304\302\304\304\304\302\304\304\304\277");
    gotoxy(coluna+1, linha);
    printf("\263   \263   \263   \263");
    gotoxy(coluna+2, linha);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");
    gotoxy(coluna+3, linha);
    printf("\263   \263   \263   \263");
    gotoxy(coluna+4,linha);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");
    gotoxy(coluna+5,linha);
    printf("\263   \263   \263   \263");
    gotoxy(coluna+6,linha);
    printf("\300\304\304\304\301\304\304\304\301\304\304\304\331");
}


//Imprime os numeros da grade escolhida
void numeros_grade_inicio(char matriz_grade[][3])
{
    int i,j;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            gotoxy(17+i*2,18+j*4);
            printf("%c",matriz_grade[i][j]);
        }
    }
}


//Imprime os numeros da grade objetivo
void numeros_grade_objetivo(char matriz_grade[][3])
{
    int i,j;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            gotoxy(17+i*2,84+j*4);
            printf("%c",matriz_grade[i][j]);
        }
    }
}
