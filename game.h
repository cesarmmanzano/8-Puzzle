/*
    8 Puzzle
    Pontifícia Universidade Católica de Campinas
    Cesar Marrote Manzano
*/


int checkEndGame(char arrayGame[][3], char arraySolution[][3]);
int exchangeNumber(char arrayGame[][3]);
void menuSolution();

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
