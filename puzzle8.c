/*
    Cesar Marrote Manzano
    8 Puzzle
    Pontifícia Universidade Católica de Campinas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void changeColor(int color);
void gotoxy(int line, int column);
void printGrid(int inicialLine, int inicialColumn);
void printGridNumbersGame(char arrayGameGrid[][3]);
void printGridNumbersSolution(char arraySolutionGrid[][3]);

void menu(int *escolha, char matriz_objetivo[][3]);
void puzzleText();
void congratulationsText();

void game(char arrayGame1[][3], char arrayGame2[][3], char arraySolution [][3], int chooseGame);
int checkEndGame(char arrayGame1[][3], char arraySolution[][3]);
int exchangeNumber(char arrayGame1[][3]);

void menuSolution();
void solution1(char arrayGame1[][3], char arraySolution[][3]);
void solution2(char arrayGame2[][3], char arraySolution[][3]);
void auxiliary(char arrayGame[][3]);


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
            printf("%c",arrayGameGrid[i][j]);
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
            printf("%c",arraySolutionGrid[i][j]);
        }
    }
}



//========================================================================//



//Print game menu
void menu(int *escolha, char matriz_objetivo[][3])
{
    char arrayMenu[3][3] = { { '7', '8', ' ' },
        { '1', '6', '5' },
        { '2', '3', '4' }
    };

    do
    {
        system("cls");

        changeColor(15);
        printf("Cesar Marrote Manzano\nRA:18051755");

        puzzleText();

        //About the game -> brief explanation
        gotoxy(11,10);
        changeColor(15);
        printf("Bem vindo! O jogo Quebra Cabeca de 8 tem como objetivo mover as pecas do quadro inicio, atraves do");
        gotoxy(12,26);
        printf("campo vazio , e no final terminar como o quadro objetivo!");


        //Game grid
        gotoxy(14,19);
        printf("INICIO");
        printGrid(16,16);
        printGridNumbersGame(arrayMenu);

        //Solution grid
        gotoxy(14,84);
        printf("OBJETIVO");
        printGrid(82,16);
        printGridNumbersSolution(matriz_objetivo);

        //User input -> Choose the game
        gotoxy(14,40);
        printf("Escolha qual jogo voce quer:");

        gotoxy(16,45);
        printf("Puzzle 1 <Digite 1>");

        gotoxy(18,45);
        printf("Puzzle 2 <Digite 2>");

        gotoxy(20,50);
        printf("Escolha:");
        scanf("%d",escolha);

    }
    while(*escolha<1 || *escolha>2);

}


//Print "8-PUZZLE"
void puzzleText()
{
    changeColor(6);
    printf("\n\t\t _______\t  \t _______\t      ______   ______\t\t ______");
    printf("\n\t\t|\t|\t  \t|\t| |\t   | |\t   /  |\t    /  |\t|");
    printf("\n\t\t|\t|\t  \t|\t| |\t   |\t  /\t   /   |\t|");
    printf("\n\t\t|_______|\t__\t|_______| |\t   |\t /\t  /    |\t|____");
    printf("\n\t\t|\t|\t  \t|\t  |\t   |\t/\t /     |\t|");
    printf("\n\t\t|\t|\t  \t|\t  |\t   |   /\t/      |\t|");
    printf("\n\t\t|_______|\t  \t|\t  |________|  /_____|  /_____| |______| |______");

    printf("\n\n\n\n\n");
}


//Print "Parabens"
void congratulationsText()
{
    changeColor(6);
    printf(" _______   _______    _______    _______    _______    _______\t\t   _______");
    printf("\n|\t| |\t  |  |\t     |  |\t|  |\t   \\  |\t\t|\\     |  |\t  |");
    printf("\n|\t| |\t  |  |\t     |  |\t|  |\t   |  | \t| \\    |  |");
    printf("\n|_______/ |_______|  |_______/  |_______|  |_______/  |_______  |  \\   |  |_______");
    printf("\n|\t  |\t  |  |  \\\t|\t|  |\t   \\  |\t\t|   \\  |\t  |");
    printf("\n|\t  |\t  |  |   \\\t|\t|  |\t   |  |\t\t|    \\ |\t  |");
    printf("\n|\t  |\t  |  |    \\\t|\t|  |_______/  |_______  |     \\|  |_______|");
}



//========================================================================//



//Game start
void game(char arrayGame1[][3], char arrayGame2[][3], char arraySolution [][3], int chooseGame)
{
    //Choose the game
    if(chooseGame == 1)
    {
        do
        {
            system("cls");

            changeColor(15);
            printf("Cesar Marrote Manzano\nRA:18051755");

            puzzleText();

            //Show arrayGame1
            changeColor(15);
            gotoxy(14,19);
            printf("INICIO");
            printGrid(16,16);
            printGridNumbersGame(arrayGame1);

            //Show arraySolution
            gotoxy(14,84);
            printf("OBJETIVO");
            printGrid(82,16);
            printGridNumbersSolution(arraySolution);

            exchangeNumber(arrayGame1);

        }
        while(!checkEndGame(arrayGame1,arraySolution));
    }

    else //Game2
    {

        do
        {
            system("cls");

            changeColor(15);
            printf("Cesar Marrote Manzano\nRA:18051755");

            puzzleText();

            //Show arrayGame2
            changeColor(15);
            gotoxy(14,19);
            printf("INICIO");
            printGrid(16,16);
            printGridNumbersGame(arrayGame2);

            //Show arraySolution
            gotoxy(14,84);
            printf("OBJETIVO");
            printGrid(82,16);
            printGridNumbersSolution(arraySolution);

            exchangeNumber(arrayGame2);
        }
        while(!checkEndGame(arrayGame2,arraySolution));
    }
}


//Check if: arrayGame = arraySolution
int checkEndGame(char arrayGame1[][3], char arraySolution[][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(arrayGame1[i][j] != arraySolution[i][j])
                return 0;
    return 1;
}


//Exchange numbers
int exchangeNumber(char arrayGame1[][3])
{
    char chosenNumber, aux;

    gotoxy(14,41);
    printf("Digite 0 para ver a solucao");

    do
    {
        //User input -> choose number to exchange
        gotoxy(16,35);
        printf("Digite o numero que voce deseja mover:");
        fflush(stdin);
        scanf("%c", &chosenNumber);
    }
    while(chosenNumber<'0' || chosenNumber>'9');

    if(chosenNumber == '0')
    {
        //Show menuSolution if the user wants to know game's solution
        menuSolution();
        printf("\n\n\n\n\n");
        exit(0);
    }


    //Exchange number -> start
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            //Check right
            if((arrayGame1[i][j] == chosenNumber) && (arrayGame1[i+1][j] == ' '))
            {
                aux=arrayGame1[i+1][j];
                arrayGame1[i+1][j]=arrayGame1[i][j];
                arrayGame1[i][j]=aux;
                return 1;
            }

            //Check left
            if((arrayGame1[i][j] == chosenNumber) && (arrayGame1[i - 1][j] == ' '))
            {
                aux=arrayGame1[i-1][j];
                arrayGame1[i-1][j]=arrayGame1[i][j];
                arrayGame1[i][j]=aux;
                return 1;
            }

            //Check up
            if((arrayGame1[i][j] == chosenNumber)&&(arrayGame1[i][j - 1] == ' '))
            {
                aux=arrayGame1[i][j-1];
                arrayGame1[i][j-1]=arrayGame1[i][j];
                arrayGame1[i][j]=aux;
                return 1;
            }

            //Check down
            if((arrayGame1[i][j] == chosenNumber)&&(arrayGame1[i][j + 1] == ' '))
            {
                aux=arrayGame1[i][j+1];
                arrayGame1[i][j+1]=arrayGame1[i][j];
                arrayGame1[i][j]=aux;
                return 1;
            }
        }
    }
    return 0;
}



//========================================================================//


//Which soluction the user wants
void menuSolution()
{
    int chooseSolution;

    int anotherSolution;

    do
    {
        char arrayGame1[3][3] = { { '4', '1', '3' },
            { '2', '8', '5' },
            { '7', ' ', '6' }
        };

        char arrayGame2[3][3] = { { '4', '1', '3' },
            { '2', ' ', '6' },
            { '7', '5', '8' }
        };

        char arraySolution[3][3] = { { '1', '2', '3' },
            { '4', '5', '6' },
            { '7', '8', ' ' }
        };

        system("cls");

        changeColor(15);
        printf("Cesar Marrote Manzano\nRA:18051755");

        puzzleText();

        changeColor(15);
        gotoxy(11,47);
        printf("Qual solucao deseja?");
        gotoxy(13,40);
        printf("<Jogo1: Digite1> <Jogo2: Digite2>");
        gotoxy(15,52);
        printf("Escolha:");
        scanf("%d",&chooseSolution);


        if(chooseSolution == 1)
            solution1(arrayGame1, arraySolution);
        else
            solution2(arrayGame2, arraySolution);

        gotoxy(18,36);
        printf("Deseja outra solucao? <0-Nao> <1-Sim>");
        scanf("%d",&anotherSolution);
    }
    while(anotherSolution!=0);
}

//Game1 solution
void solution1(char arrayGame1[][3], char arraySolution[][3])
{
    char aux;

    gotoxy(14,84);
    printf("OBJETIVO");
    printGrid(82,16);
    printGridNumbersSolution(arraySolution);

    auxiliary(arrayGame1);

    aux=arrayGame1[2][1];
    arrayGame1[2][1] = arrayGame1[1][1];
    arrayGame1[1][1]=aux;
    Sleep(800);
    auxiliary(arrayGame1);

    aux=arrayGame1[1][0];
    arrayGame1[1][0] = arrayGame1[1][1];
    arrayGame1[1][1]=aux;
    Sleep(800);
    auxiliary(arrayGame1);

    aux=arrayGame1[1][0];
    arrayGame1[1][0]=arrayGame1[0][0];
    arrayGame1[0][0]=aux;
    Sleep(800);
    auxiliary(arrayGame1);

    aux=arrayGame1[0][0];
    arrayGame1[0][0]=arrayGame1[0][1];
    arrayGame1[0][1]=aux;
    Sleep(800);
    auxiliary(arrayGame1);

    aux=arrayGame1[0][1];
    arrayGame1[0][1]=arrayGame1[1][1];
    arrayGame1[1][1]=aux;
    Sleep(800);
    auxiliary(arrayGame1);

    aux=arrayGame1[1][1];
    arrayGame1[1][1]=arrayGame1[1][2];
    arrayGame1[1][2]=aux;
    Sleep(800);
    auxiliary(arrayGame1);

    aux=arrayGame1[1][2];
    arrayGame1[1][2]=arrayGame1[2][2];
    arrayGame1[2][2]=aux;
    Sleep(800);
    auxiliary(arrayGame1);
}

//Game2 soluction
void solution2(char arrayGame2[][3], char arraySolution[][3])
{
    char aux;

    gotoxy(14,84);
    printf("OBJETIVO");
    printGrid(82,16);
    printGridNumbersSolution(arraySolution);

    auxiliary(arrayGame2);

    aux=arrayGame2[1][1];
    arrayGame2[1][1]=arrayGame2[1][0];
    arrayGame2[1][0]=aux;
    Sleep(800);
    auxiliary(arrayGame2);

    aux=arrayGame2[1][0];
    arrayGame2[1][0] = arrayGame2[0][0];
    arrayGame2[0][0]=aux;
    Sleep(800);
    auxiliary(arrayGame2);

    aux=arrayGame2[0][0];
    arrayGame2[0][0]=arrayGame2[0][1];
    arrayGame2[0][1]=aux;
    Sleep(800);
    auxiliary(arrayGame2);

    aux=arrayGame2[0][1];
    arrayGame2[0][1]=arrayGame2[1][1];
    arrayGame2[1][1]=aux;
    Sleep(800);
    auxiliary(arrayGame2);

    aux=arrayGame2[1][1];
    arrayGame2[1][1]=arrayGame2[2][1];
    arrayGame2[2][1]=aux;
    Sleep(800);
    auxiliary(arrayGame2);

    aux=arrayGame2[2][1];
    arrayGame2[2][1]=arrayGame2[2][2];
    arrayGame2[2][2]=aux;
    Sleep(800);
    auxiliary(arrayGame2);
}


//Print the array after each exchange
void auxiliary(char arrayGame[][3])
{
    changeColor(15);
    changeColor(15);
    gotoxy(14,19);
    printf("INICIO");
    printGrid(16,16);
    printGridNumbersGame(arrayGame);
}
