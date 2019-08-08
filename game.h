/*
Puzzle 8
Pontifícia Universidade Católica de Campinas
Cesar Marrote Manzano
*/

int verificacao_terminou(char matriz_inicio[][3], char matriz_objetivo[][3]);
int troca_numero(char matriz_inicio[][3]);
void solucao_menu();

//Função que chama as outras funções do jogo e inicia
void jogo(char matriz_inicio[][3], char matriz_inicio2[][3], char matriz_objetivo [][3], int escolha_jogo)
{
    //Verifica a escolha do jogo e executa adequadamente
    if(escolha_jogo == 1)
    {
        do
        {
            system("cls");

            mudacor(15);
            printf("Cesar Marrote Manzano\nRA:18051755");

            puzzle_texto();

            //Grade inicio
            mudacor(15);
            gotoxy(14,19);
            printf("INICIO");
            imprime_grade(16,16);
            numeros_grade_inicio(matriz_inicio);

            //Grade objetivo
            gotoxy(14,84);
            printf("OBJETIVO");
            imprime_grade(82,16);
            numeros_grade_objetivo(matriz_objetivo);

            troca_numero(matriz_inicio);

        }
        while(!verificacao_terminou(matriz_inicio,matriz_objetivo));
    }

    else
    {

        do
        {
            system("cls");

            mudacor(15);
            printf("Cesar Marrote Manzano\nRA:18051755");

            puzzle_texto();

            //Grade inicio
            mudacor(15);
            gotoxy(14,19);
            printf("INICIO");
            imprime_grade(16,16);
            numeros_grade_inicio(matriz_inicio2);

            //Grade objetivo
            gotoxy(14,84);
            printf("OBJETIVO");
            imprime_grade(82,16);
            numeros_grade_objetivo(matriz_objetivo);

            troca_numero(matriz_inicio2);
        }
        while(!verificacao_terminou(matriz_inicio2,matriz_objetivo));
    }
}


//Função que verifica se a matriz inicial é igual a matriz objetivo
int verificacao_terminou(char matriz_inicio[][3], char matriz_objetivo[][3])
{
    int i,j;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(matriz_inicio[i][j] != matriz_objetivo[i][j])
                return 0;
    return 1;
}


//Função que fará a troca dos números
int troca_numero(char matriz_inicio[][3])
{
    char num_escolhido,aux;

    int i,j;

    gotoxy(14,41);
    printf("Digite 0 para ver a solucao");

    do
    {
        //Escolha do número desejado
        gotoxy(16,35);
        printf("Digite o numero que voce deseja mover:");
        fflush(stdin);
        scanf("%c", &num_escolhido);
    }
    while(num_escolhido<'0' || num_escolhido>'9');

    if(num_escolhido=='0')
    {
        //Chama a solucao caso o numero escolhido for 0
        solucao_menu();
        printf("\n\n\n\n\n");
        exit(0);
    }


    //Início da troca de número
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {

            //Direita
            if((matriz_inicio[i][j] == num_escolhido) && (matriz_inicio[i+1][j] == ' '))
            {
                aux=matriz_inicio[i+1][j];
                matriz_inicio[i+1][j]=matriz_inicio[i][j];
                matriz_inicio[i][j]=aux;
                return 1;
            }

            //Esquerda
            if((matriz_inicio[i][j] == num_escolhido) && (matriz_inicio[i - 1][j] == ' '))
            {
                aux=matriz_inicio[i-1][j];
                matriz_inicio[i-1][j]=matriz_inicio[i][j];
                matriz_inicio[i][j]=aux;
                return 1;
            }

            //Cima
            if((matriz_inicio[i][j] == num_escolhido)&&(matriz_inicio[i][j - 1] == ' '))
            {
                aux=matriz_inicio[i][j-1];
                matriz_inicio[i][j-1]=matriz_inicio[i][j];
                matriz_inicio[i][j]=aux;
                return 1;
            }

            //Baixo
            if((matriz_inicio[i][j] == num_escolhido)&&(matriz_inicio[i][j + 1] == ' '))
            {
                aux=matriz_inicio[i][j+1];
                matriz_inicio[i][j+1]=matriz_inicio[i][j];
                matriz_inicio[i][j]=aux;
                return 1;
            }
        }
    }
    return 0;
}
