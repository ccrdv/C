#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>  
#include <windows.h> 

char tabuleiro[3][3];
const char jogador1 = 'X';
const char jogador2 = 'O'; 

void reiniciarTabuleiro(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprime_tabuleiro() {
   printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
   printf("--- |--- | ---\n");
   printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
   printf("--- |--- | ---\n");
   printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
   printf("\n\n");
}
int verificarCasa(){
    int casasLivres = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] != ' '){
                casasLivres--;
            }
        }
    }
            
    return casasLivres;
}

void jogadaP1(){
    int x, y;
    do{
        printf("Jogador 1 (X) - Sua vez!\n");
        printf("Digite a linha (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Digite a coluna (1-3): ");
        scanf("%d", &y);
        y--;
        printf("\n");
        if(tabuleiro[x][y] != ' '){
            printf("Casa ja ocupada! Tente novamente.\n");
            printf("\n");
        }
        else{
            tabuleiro[x][y] = jogador1;
            break;
        }
    } while(tabuleiro[x][y] != ' ');
}
void jogadaP2(){
    int x, y;
    do{
        printf("Jogador 2 (O) - Sua vez!\n");
        printf("Digite a linha (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Digite a coluna (1-3): ");
        scanf("%d", &y);
        y--;
        printf("\n");
        if(tabuleiro[x][y] != ' '){
            printf("Casa ja ocupada! Tente novamente.\n");
            printf("\n");
        }
        else{
            tabuleiro[x][y] = jogador2;
            break;
        }
    } while(tabuleiro[x][y] != ' ');
}
char venceu(){
    for(int i = 0; i < 3; i++){
        if(tabuleiro[i][0] == tabuleiro [i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
            return tabuleiro[i][0];
        }
    }
    for(int j = 0; j < 3; j++){
        if(tabuleiro[0][j] == tabuleiro [1][j] && tabuleiro[1][j] == tabuleiro[2][j]){
            return tabuleiro[0][j];
        }
    }
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
        return tabuleiro[0][0];
    }
    if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
        return tabuleiro[0][2];
    }
    return ' ';
}
void mostraVencedor(char venceu){
    if(venceu == jogador1){
        print("\n\t --- Fim de Jogo --- \n");
        printf(" *** Jogador 1 (X) venceu! ***\n");
    }
    else if(venceu == jogador2){
        print("\n\t --- Fim de Jogo --- \n");
        printf(" *** Jogador 2 (O) venceu! ***\n");
    }
    else{
        print("\n\t --- Fim de Jogo --- \n");
        printf(" *** VELHA! ***\n");
    }
}
int main(){
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("\n\n");
    printf("*****************************************************\n");
    printf("                    Jogo da Velha                     \n");
    printf("*****************************************************\n");
    printf("\tJogador 1 = X\n");
    printf("\tJogador 2 = O\n");
    printf("\n");
    char vencedor = ' ';

    reiniciarTabuleiro();
    while(venceu == ' ' && verificarCasa() != 0){
        imprime_tabuleiro();
        jogadaP1();
        vencedor = venceu();
        if(vencedor != ' ' || verificarCasa() == 0){
            break;
        }
        imprime_tabuleiro();
        jogadaP2();
        vencedor = venceu();
        if(vencedor != ' ' || verificarCasa() == 0){
            break;
        }
    }
    imprime_tabuleiro();
    mostraVencedor(vencedor);
    system("pause");
    return 0;
}

