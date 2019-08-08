/*
Puzzle 8
Pontifícia Universidade Católica de Campinas
Cesar Marrote Manzano
*/

void mudacor(int cor);
void gotoxy(int linha, int coluna);
void imprime_grade(int linha_inicial, int col_inicial);
void numeros_grade_inicio(char matriz_grade[][3]);
void numeros_grade_objetivo(char matriz_grade[][3]);

void puzzle_texto();

//Imprime o menu do jogo
void menu(int *escolha, char matriz_objetivo[][3])
{
    char matriz_menu[3][3] = { { '7', '8', ' ' },
        { '1', '6', '5' },
        { '2', '3', '4' }
    };

    do
    {
        system("cls");

        mudacor(15);
        printf("Cesar Marrote Manzano\nRA:18051755");

        puzzle_texto();

        //Explicação breve sobre o jogo
        gotoxy(11,10);
        mudacor(15);
        printf("Bem vindo! O jogo Quebra Cabeca de 8 tem como objetivo mover as pecas do quadro inicio, atraves do");
        gotoxy(12,26);
        printf("campo vazio , e no final terminar como o quadro objetivo!");


        //Grade início
        gotoxy(14,19);
        printf("INICIO");
        imprime_grade(16,16);
        numeros_grade_inicio(matriz_menu);

        //Grade objetivo
        gotoxy(14,84);
        printf("OBJETIVO");
        imprime_grade(82,16);
        numeros_grade_objetivo(matriz_objetivo);

        //Mensagem qual jogo o usuário quer
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


//Funçao que imprime a palavra "8-PUZZLE"
void puzzle_texto()
{
    mudacor(6);
    printf("\n\t\t _______\t  \t _______\t      ______   ______\t\t ______");
    printf("\n\t\t|\t|\t  \t|\t| |\t   | |\t   /  |\t    /  |\t|");
    printf("\n\t\t|\t|\t  \t|\t| |\t   |\t  /\t   /   |\t|");
    printf("\n\t\t|_______|\t__\t|_______| |\t   |\t /\t  /    |\t|____");
    printf("\n\t\t|\t|\t  \t|\t  |\t   |\t/\t /     |\t|");
    printf("\n\t\t|\t|\t  \t|\t  |\t   |   /\t/      |\t|");
    printf("\n\t\t|_______|\t  \t|\t  |________|  /_____|  /_____| |______| |______");

    printf("\n\n\n\n\n");
}


//Função que imprime a palavra "Parabens"
void parabens_texto()
{
    mudacor(6);
    printf(" _______   _______    _______    _______    _______    _______\t\t   _______");
    printf("\n|\t| |\t  |  |\t     |  |\t|  |\t   \\  |\t\t|\\     |  |\t  |");
    printf("\n|\t| |\t  |  |\t     |  |\t|  |\t   |  | \t| \\    |  |");
    printf("\n|_______/ |_______|  |_______/  |_______|  |_______/  |_______  |  \\   |  |_______");
    printf("\n|\t  |\t  |  |  \\\t|\t|  |\t   \\  |\t\t|   \\  |\t  |");
    printf("\n|\t  |\t  |  |   \\\t|\t|  |\t   |  |\t\t|    \\ |\t  |");
    printf("\n|\t  |\t  |  |    \\\t|\t|  |_______/  |_______  |     \\|  |_______|");
}
