/*
    8 Puzzle
    Pontifícia Universidade Católica de Campinas
    Cesar Marrote Manzano
*/

void changeColor(int color);
void gotoxy(int line, int column);
void printGrid(int inicialLine, int inicialColumn);
void printGridNumbersGame(char arrayGameGrid[][3]);
void printGridNumbersSolution(char arraySolutionGrid[][3]);
void puzzleText();

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
