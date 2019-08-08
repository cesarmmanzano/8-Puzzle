/*
Puzzle 8
Pontifícia Universidade Católica de Campinas
Cesar Marrote Manzano
*/

void solucao1(char matriz_inicioS[][3], char matriz_objetivoS[][3]);
void solucao2(char matriz_inicioS2[][3], char matriz_objetivoS[][3]);
void ajuda(char matriz_inicioS[][3]);

//Função que pergunta qual solucao o usuario deseja e executa adequadamente
void solucao_menu()
{
    int escolha_solucao;

    int solucao_denovo;

    do
    {
        char matriz_inicioS[3][3] = { { '4', '1', '3' },
            { '2', '8', '5' },
            { '7', ' ', '6' }
        };

        char matriz_inicioS2[3][3] = { { '4', '1', '3' },
            { '2', ' ', '6' },
            { '7', '5', '8' }
        };

        char matriz_objetivoS[3][3] = { { '1', '2', '3' },
            { '4', '5', '6' },
            { '7', '8', ' ' }
        };

        system("cls");

        mudacor(15);
        printf("Cesar Marrote Manzano\nRA:18051755");

        puzzle_texto();

        mudacor(15);
        gotoxy(11,47);
        printf("Qual solucao deseja?");
        gotoxy(13,40);
        printf("<Jogo1: Digite1> <Jogo2: Digite2>");
        gotoxy(15,52);
        printf("Escolha:");
        scanf("%d",&escolha_solucao);


        if(escolha_solucao==1)
            solucao1(matriz_inicioS, matriz_objetivoS);
        else
            solucao2(matriz_inicioS2, matriz_objetivoS);

        gotoxy(18,36);
        printf("Deseja outra solucao? <0-Nao> <1-Sim>");
        scanf("%d",&solucao_denovo);
    }
    while(solucao_denovo!=0);
}

//Solucao do jogo1
void solucao1(char matriz_inicioS[][3], char matriz_objetivoS[][3])
{
    char aux;

    gotoxy(14,84);
    printf("OBJETIVO");
    imprime_grade(82,16);
    numeros_grade_objetivo(matriz_objetivoS);

    ajuda(matriz_inicioS);

    aux=matriz_inicioS[2][1];
    matriz_inicioS[2][1] = matriz_inicioS[1][1];
    matriz_inicioS[1][1]=aux;
    Sleep(800);
    ajuda(matriz_inicioS);

    aux=matriz_inicioS[1][0];
    matriz_inicioS[1][0] = matriz_inicioS[1][1];
    matriz_inicioS[1][1]=aux;
    Sleep(800);
    ajuda(matriz_inicioS);

    aux=matriz_inicioS[1][0];
    matriz_inicioS[1][0]=matriz_inicioS[0][0];
    matriz_inicioS[0][0]=aux;
    Sleep(800);
    ajuda(matriz_inicioS);

    aux=matriz_inicioS[0][0];
    matriz_inicioS[0][0]=matriz_inicioS[0][1];
    matriz_inicioS[0][1]=aux;
    Sleep(800);
    ajuda(matriz_inicioS);

    aux=matriz_inicioS[0][1];
    matriz_inicioS[0][1]=matriz_inicioS[1][1];
    matriz_inicioS[1][1]=aux;
    Sleep(800);
    ajuda(matriz_inicioS);

    aux=matriz_inicioS[1][1];
    matriz_inicioS[1][1]=matriz_inicioS[1][2];
    matriz_inicioS[1][2]=aux;
    Sleep(800);
    ajuda(matriz_inicioS);

    aux=matriz_inicioS[1][2];
    matriz_inicioS[1][2]=matriz_inicioS[2][2];
    matriz_inicioS[2][2]=aux;
    Sleep(800);
    ajuda(matriz_inicioS);
}

//Solucao do jogo2
void solucao2(char matriz_inicioS2[][3], char matriz_objetivoS[][3])
{
    char aux;

    gotoxy(14,84);
    printf("OBJETIVO");
    imprime_grade(82,16);
    numeros_grade_objetivo(matriz_objetivoS);

    ajuda(matriz_inicioS2);

    aux=matriz_inicioS2[1][1];
    matriz_inicioS2[1][1] = matriz_inicioS2[1][0];
    matriz_inicioS2[1][0]=aux;
    Sleep(800);
    ajuda(matriz_inicioS2);

    aux=matriz_inicioS2[1][0];
    matriz_inicioS2[1][0] = matriz_inicioS2[0][0];
    matriz_inicioS2[0][0]=aux;
    Sleep(800);
    ajuda(matriz_inicioS2);

    aux=matriz_inicioS2[0][0];
    matriz_inicioS2[0][0]=matriz_inicioS2[0][1];
    matriz_inicioS2[0][1]=aux;
    Sleep(800);
    ajuda(matriz_inicioS2);

    aux=matriz_inicioS2[0][1];
    matriz_inicioS2[0][1]=matriz_inicioS2[1][1];
    matriz_inicioS2[1][1]=aux;
    Sleep(800);
    ajuda(matriz_inicioS2);

    aux=matriz_inicioS2[1][1];
    matriz_inicioS2[1][1]=matriz_inicioS2[2][1];
    matriz_inicioS2[2][1]=aux;
    Sleep(800);
    ajuda(matriz_inicioS2);

    aux=matriz_inicioS2[2][1];
    matriz_inicioS2[2][1]=matriz_inicioS2[2][2];
    matriz_inicioS2[2][2]=aux;
    Sleep(800);
    ajuda(matriz_inicioS2);
}


//Função auxiliar para imprimir a matriz após cada troca
void ajuda(char matriz_inicioS[][3])
{
    mudacor(15);
    mudacor(15);
    gotoxy(14,19);
    printf("INICIO");
    imprime_grade(16,16);
    numeros_grade_inicio(matriz_inicioS);
}
