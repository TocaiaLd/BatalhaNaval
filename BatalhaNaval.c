#include <stdio.h>
#include <stdbool.h>


void NavioNaHorizontal(int posicao[6], int Tabuleiro[10][10]){
    //verificar se todas as posições estão livres
    bool verificarPosicao = 1;
    // For feito para verificar o x e y alternado do array navioHorizontal
    for(int i=0, j=1; i<=4 && j<=5; i+=2, j+=2){
        //imprimir erro caso a posição do navio não exista no tabuleiro
        if(posicao[i] > 9 || posicao[j] >9 || posicao[i] < 0 || posicao[j] < 0){
            printf("Essa linha/coluna não existe, por favor escolha uma linha existente");
            verificarPosicao = 0;
            break;
        }
        // Imprimir erro caso o navio não possa ser completado por falta de espaço a direita
        if(i==0 && posicao[j]>7){
            printf("Essa coluna não existe, por favor escolha uma linha existente");
            verificarPosicao = 0;
            break;
        }
        if(Tabuleiro[posicao[i]] [posicao[j]] == 3){
            verificarPosicao = 0;
            break;
        }
    }

    //Verificando todos os pontos do eixo X estão iguais
    bool teste1 = (posicao[0]==posicao[2]) && (posicao[2] == posicao[4]);

    //verificar se os pontos do eixo y são difentes
    bool teste3 = (posicao[1] == posicao[3]) || (posicao[3]== posicao[5]) || (posicao[1] == posicao[5]) ? 0 : 1;

    //Verificando se os pontos do eixo y estão em ordem crescente/decrescente
    //Ou seja, vendo se as colunas são adjacentes
    bool teste2 = (posicao[1] + 1 == posicao[3]) && (posicao[3] + 1 == posicao[5]) || (posicao[1] - 1 == posicao[3]) && (posicao[3] - 1 == posicao[5]) ;

    // Verificando se ambas as condições deram TRUE para poder passar o navio para 
    // o tabuleiro
    if(teste1 && teste2 && teste3 && verificarPosicao){
        for(int i=0, j=1; i<=4 && j<=5; i+=2, j+=2){
            Tabuleiro[posicao[i]] [posicao[j]] = 3;
        } 
    }else{
        printf("entrada nao valida\n");
    }
}


void NavioNaVertical(int posicao[6], int Tabuleiro[10][10]){
    //verificar se todas as posições estão livres
    bool verificarPosicao = 1;

    // For feito para verificar o x e y alternado do array vertical
    for(int i=0, j=1; i<=4 && j<=5; i+=2, j+=2){
        //imprimir erro caso a posição do navio não exista no tabuleiro
        if(posicao[i] > 9 || posicao[j] >9 || posicao[i] < 0 || posicao[j] < 0){
            printf("Essa linha/coluna não existe, por favor escolha uma linha existente");
            verificarPosicao = 0;
            break;
        }
        // Imprimir erro caso o navio não possa ser completado por falta de espaço abaixo
        if(i==0 && posicao[i]>7){
            printf("Essa linha não existe, por favor escolha uma linha existente");
            verificarPosicao = 0;
            break;
        }
        if(Tabuleiro[posicao[i]] [posicao[j]] == 3){
            verificarPosicao = 0;
            break;
        }
    }

    //Verificando todos os pontos do eixo y estão iguais
    bool teste1 = (posicao[1]==posicao[3]) && (posicao[3] == posicao[5]);

    //verificar se os pontos do eixo x são difentes
    bool teste3 = (posicao[0] == posicao[2]) || (posicao[2]== posicao[4]) || (posicao[0] == posicao[4]) ? 0 : 1;

    //Verificando se os pontos do eixo x estão em ordem crescente/decrescente
    //Ou seja, vendo se as colunas são adjacentes
    int navioVertical[6] = {4,3,5,3,6,3};
    bool teste2 = (posicao[0] + 1 == posicao[2]) && (posicao[2] + 1 == posicao[4]) || (posicao[0] - 1 == posicao[2]) && (posicao[2] - 1 == posicao[4]) ;

    // Verificando se ambas as condições deram TRUE para poder passar o navio para 
    // o tabuleiro
    if(teste1 && teste2 && teste3 && verificarPosicao){
        for(int i=0, j=1; i<=4 && j<=5; i+=2, j+=2){
            Tabuleiro[posicao[i]] [posicao[j]] = 3;
        } 
    }else{
        printf("entrada nao valida\n");
    }
}

int main(){
    
    // criação da matriz do tabuleiro
    // 0 -> agua
    // 3 -> navio
    int Tabuleiro[10][10] = 
    {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
    };
    
    // Array com posição do navio horizontal
    // intercalando em x,y,x,y,x,y
    int navioHorizontal1[6] = {9,1,9,2,9,3};
    NavioNaHorizontal(navioHorizontal1, Tabuleiro);

    // Array com posição do navio vertical
    // intercalando em x,y,x,y,x,y
    int navioVertical[6] = {6,3,7,3,8,3};
    NavioNaVertical(navioVertical, Tabuleiro);

    //enviando o tabuleiro em forma de texto para o terminal
    for(int i=0; i<=9; i++){
        for(int j=0; j<=9; j++){
            if(j==9){
                printf("%d\n", Tabuleiro[i][j]);
                break;
            }
            printf("%d ", Tabuleiro[i][j]);
        }
    }

    return 0;

}