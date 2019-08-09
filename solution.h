/*
    8 Puzzle
    Pontifícia Universidade Católica de Campinas
    Cesar Marrote Manzano
*/

void solution1(char arrayGame1[][3], char arraySolution[][3]);
void solution2(char arrayGame2[][3], char arraySolution[][3]);
void auxiliary(char arrayGame[][3]);


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
