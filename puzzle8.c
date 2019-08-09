/*
    8 Puzzle
    Pontifícia Universidade Católica de Campinas
    Cesar Marrote Manzano
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "menu.h"
#include "game.h"
#include "solution.h"


void changeColor(int color);
void gotoxy(int line, int column);
void printGrid(int inicialLine, int inicialColumn);
void printGridNumbersGame(char arrayGameGrid[][3]);
void printGridNumbersSolution(char arraySolutionGrid[][3]);


void main()
{
    int chooseGameGrid, playAgain;

    do
    {

        /*
            Arrays:
            1 Solution array
            2 Game array
        */

        char arraySolution[3][3] = { { '1', '2', '3' },
            { '4', '5', '6' },
            { '7', '8', ' ' }
        };

        char arrayGame1[3][3] = { { '4', '1', '3' },
            { '2', '8', '5' },
            { '7', ' ', '6' }
        };

        char arrayGame2[3][3] = { { '4', '1', '3' },
            { '2', ' ', '6' },
            { '7', '5', '8' }
        };



        //========================================================================//


        menu(&chooseGameGrid, arraySolution);

        game(arrayGame1, arrayGame2, arraySolution, chooseGameGrid);

        system("cls");
        congratulationsText();

        changeColor(15);
        printf("\n\nVoce deseja jogar novamente?<0-Nao><1-Sim>");
        scanf("%d", &playAgain);
    }
    while(playAgain == 1);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
}


//Change color
void changeColor(int color)
{
    /*
    Lista de cores:
    0 = Black		        8 = Grey
    1 = Blue		        9 = Light Blue
    2 = Green		        10 = Light Green
    3 = Green Watercolor	11 = Light Green Watercolor
    4 = Red	                12 = Light Red
    5 = Purple		        13 = Lilac
    6 = Yellow		        14 = Light Yellow
    7 = White		        15 = Bright White
    */

    HANDLE Exit;
    Exit = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Exit,color);
}


//Used to take the cursor to a particular co-ordinate of the screen
void gotoxy(int line, int column)
{
    HANDLE Exit;
    COORD Position;

    Exit = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = column;
    Position.Y = line;

    SetConsoleCursorPosition(Exit, Position);
}


//Print grid -> 8 Puzzle
void printGrid(int inicialLine, int inicialColumn)
{
    int line = inicialLine;
    int column = inicialColumn;

    gotoxy(column, line);
    printf("\332\304\304\304\302\304\304\304\302\304\304\304\277");
    gotoxy(column+1, line);
    printf("\263   \263   \263   \263");
    gotoxy(column+2, line);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");
    gotoxy(column+3, line);
    printf("\263   \263   \263   \263");
    gotoxy(column+4,line);
    printf("\303\304\304\304\305\304\304\304\305\304\304\304\264");
    gotoxy(column+5,line);
    printf("\263   \263   \263   \263");
    gotoxy(column+6,line);
    printf("\300\304\304\304\301\304\304\304\301\304\304\304\331");
}


//Print grid numbers -> Game
void printGridNumbersGame(char arrayGameGrid[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            gotoxy(17+i*2,18+j*4);
            printf("%c",arrayGame[i][j]);
        }
    }
}


//Print grid numbers -> Solution
void printGridNumbersSolution(char arraySolutionGrid[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            gotoxy(17+i*2,84+j*4);
            printf("%c",arraySolution[i][j]);
        }
    }
}
