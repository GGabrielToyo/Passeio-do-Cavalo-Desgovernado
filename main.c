#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define LIM 8

void executando_movimentos() //Aqui usu�rio entra com a casa inicial e a l�gica faz as poss�veis movimenta��es. A cada movimento feito o tabuleiro e printado na tela.
{                   setlocale(LC_ALL,"");

     int pos_inicial;
    int i = 0;
    int j = 0;
    int l = 0;
    int c = 0;
    int cont = 1;  //Inicia o tabuleiro com os n�meros consecutivos.
    int cont_jogadas_feitas = 1; //Conta as jogadas que foram feitas.
    int cont_casas_nao_visitadas = 0; //Conta as casas que o cavalo n�o passou.
    int print_casas = 1; //Contador que incrementa as casas por onde o cavalo passar.
    int num_aleatorio; //N�mero aleatorio para escolher qual dos movimentos v�lidos ser� feito.
    int jogadas_invalidas; //Contador para saber quais movimentos s�o inv�lidos.
    int matriz[LIM][LIM]; //Matriz do tabuleiro.
    int vetor_jogadas[LIM]; //Vetor que guarda as movimenta��es v�lidas.

        printf("\n\n");
    for (i = 0; i < LIM; i++) {
        for (j = 0; j < LIM; j++) {
            matriz[i][j] = cont;
            printf("\t[ %i ]", matriz[i][j]);
            cont++;
        }
        printf("\n");
    }
    printf("\n");

    cont = 1;
    printf("\tIndique a posi��o de partida (casa inicial) do cavalo: ");
    scanf("%i", &pos_inicial);

    for (i = 0; i < LIM; i++) {
        for (j = 0; j < LIM; j++) {
            matriz[i][j] = cont;
            cont++;
            if (matriz[i][j] == pos_inicial) {
                matriz[i][j] = 1;
                l = i;
                c = j;
              } else {
                matriz[i][j] = 0;
            }
        }
    }



        do {

        for (i = 0; i < LIM; i++) {
            vetor_jogadas[i] = 0;
        }

            jogadas_invalidas = 0;

           if( (l + 1 <= 7)&&(c + 2 <= 7) ) {  //1 casa p/ baixo e 2 p/ diretita
            if (matriz[l + 1][c + 2] == 0) {
                vetor_jogadas[0] = 1;
        }
       }

        if ( (l + 1 <= 7)&&(c - 2 >= 0) ) {  // 1 casa p/ baixo e 2 p/ esquerda
            if (matriz[l + 1][c - 2] == 0) {
                vetor_jogadas[1] = 2;

            }
        }

        if ( (l - 1 >= 0)&&(c + 2 <= 7) ) {  // 1 casa p/ cima e 2 p/ direita
            if (matriz[l - 1][c + 2] == 0) {
                vetor_jogadas[2] = 3;

            }
        }

        if ( (l - 1 >= 0)&&(c - 2 >= 0) ) {  //1 casa p/ cima e 2 p/ esquerda
            if (matriz[l - 1][c - 2]  == 0) {
                vetor_jogadas[3] = 4;
            }
        }

        if ( (l + 2 <= 7)&&(c + 1 <= 7) ) {  //2 casas p/ baixo e 1 p/ direita
            if (matriz[l + 2][c + 1] == 0) {
                vetor_jogadas[4] = 5;
            }
        }

        if ( (l + 2 <= 7)&&(c - 1 >= 0) ) {  //2 casas p/ baixo e 1 p/ esquerda
            if (matriz[l + 2][c - 1] == 0) {
                vetor_jogadas[5] = 6;
            }
        }
        if ( (l - 2 >= 0)&&(c + 1 <= 7) ) {   //2 p/ cima e 1 p/ direita
            if (matriz[l - 2][c + 1] == 0) {
                vetor_jogadas[6] = 7;
            }
        }
        if ( (l - 2 >= 0)&&(c - 1 >= 0) ) {  // 2 p/ cima e 1 p/esquerda
            if (matriz[l - 2][c - 1] == 0) {
                vetor_jogadas[7] = 8;
            }
        }

            for (i = 0; i < LIM; i++) {
                if (vetor_jogadas[i] == 0) {
                    jogadas_invalidas++;
                }
            }

            if (jogadas_invalidas != 8) {

              srand(time(NULL));
            do { // Gerando o n�mero aleatorio  onde o vetor_jogadas n�o tenha um valor 0.
                num_aleatorio = rand() % 7;
            }   while (vetor_jogadas[num_aleatorio] == 0);

           switch (num_aleatorio) { // Aqui vai ser escolhido a movimenta��o conforme o n�mero aleat�rio.
        case 0:
            print_casas++;
            l = l + 1;
            c = c + 2;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        case 1:
            print_casas++;
            l = l + 1;
            c = c - 2;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        case 2:
            print_casas++;
            l = l - 1;
            c = c + 2;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        case 3:
            print_casas++;
            l = l - 1;
            c = c - 2;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        case 4:
            print_casas++;
            l = l + 2;
            c = c + 1;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        case 5:
            print_casas++;
            l = l + 2;
            c = c - 1;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        case 6:
            print_casas++;
            l = l - 2;
            c = c + 1;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        case 7:
            print_casas++;
            l = l - 2;
            c = c - 1;
            matriz[l][c] = print_casas;
            cont_jogadas_feitas++;
            break;
        }

    }

    for (i = 0; i < LIM; i++) {
                for (j = 0; j < LIM; j++) {
                    printf("[ %i ]", matriz[i][j]);
                }
                printf("\n");
    }

    printf("\n\n");

        } while (jogadas_invalidas != 8);

            for (i = 0; i < LIM; i++) {
                for (j = 0; j < LIM; j++) {
                    if (matriz[i][j] == 0) {
                      cont_casas_nao_visitadas++;
                    }
                }
            }
                printf("\n");

           printf("\t Quantidade de casas visitadas foi de %i.\n", cont_jogadas_feitas);
           printf("\t Quantidade de casas n�o visitadas foi de %i.\n\n", cont_casas_nao_visitadas);

 return 0;
}

int menu () { //Menu para usu�rio iniciar o jogo ou encerrar o programa.

        setlocale(LC_ALL,"");
        char s[30];
        int resposta; //Guarda a resposta do usu�rio.

        printf("\n");
        printf("\t\t\t\t:::::::::::::::::::::::BEM VINDO:::::::::::::::::::::::\n\n\n");
        printf("\n");
        printf("\tMenu\n");
        printf("\tINSTRU��ES: INSIRA APENAS N�MEROS. OBRIGADO!!!\n\n");
        printf("\t[1] Iniciar Jogo\n");
        printf("\t[2] Sair do programa\n");


        do {
            printf("\tEntre com sua escolha: ");
            gets(s);
            resposta = atoi(s);
            if (resposta < 1 || resposta > 2) {
                printf("\tOp��o inv�lida.\n");
            }
        } while (resposta < 1 || resposta > 2);

    return resposta;
    return 0;
}



int main() {
            int resposta;
            char flag;

            resposta = menu(); //Busca por refer�ncia a resposta inserida no menu.

          do {

         switch (resposta) {

            case 1:
                system("cls");
                executando_movimentos();
                printf("\tDigite :\n");
                printf("\t[1] Para fazer uma nova simula��o.\n"); //Se 1 for escolhido vai direto para inserir a casa inicial.
                printf("\t[2] Para voltar ao menu.\n"); //Se 2 for escolhido ele vai para o menu.
                printf("\t[ ] Qualquer tecla para encerrar.\n"); //Qualquer tecla para encerrar.
                scanf("%s", &flag);
                break;
            case 2:
                printf("\tEncerrando...\n");
                exit(0);
                break;

            }

            if (flag == '1') {
                        system("cls");
                   resposta = 1;
            }

            if (flag == '2') {
                    system("cls");
                resposta = menu();
            }


          } while (flag == '1' || flag == '2');

          printf("Encerrando...");

    return 0;
}






