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

void NavioNaDiagonal(int posicao[6], int Tabuleiro[10][10]){
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
        if(i==0 && posicao[i]>7 && posicao[i+2] > 8 || i==0 && posicao[j]>7 && posicao[j+2] > 8){
            printf("Essa linha/coluna não existe, por favor escolha uma linha existente");
            verificarPosicao = 0;
            break;
        }
        if(Tabuleiro[posicao[i]] [posicao[j]] == 3){
            verificarPosicao = 0;
            printf("ja tem um navio nesse local");
            break;
        }
    }

    //Verificando todos os pontos do eixo y estão diferentes
    bool teste1 = (posicao[1]!=posicao[3]) && (posicao[3] != posicao[5]);

    //verificar se os pontos do eixo x são difentes
    bool teste3 = (posicao[0] == posicao[2]) || (posicao[2] == posicao[4]) || (posicao[0] == posicao[4]) ? 0 : 1;

    //Verificando se os pontos do eixo x estão em ordem crescente/decrescente
    //Ou seja, vendo se as colunas são adjacentes
    bool teste2 = (posicao[0] + 1 == posicao[2]) && (posicao[2] + 1 == posicao[4]) || (posicao[0] - 1 == posicao[2]) && (posicao[2] - 1 == posicao[4]) ;

    //Verificando se os pontos do eixo y estão em ordem crescente/decrescente
    //Ou seja, vendo se as colunas são adjacentes
    bool teste4 = (posicao[1] + 1 == posicao[3]) && (posicao[3] + 1 == posicao[5]) || (posicao[1] - 1 == posicao[3]) && (posicao[3] - 1 == posicao[5]) ;

    // Verificando se ambas as condições deram TRUE para poder passar o navio para 
    // o tabuleiro
    if(teste1 && teste3 && verificarPosicao && (teste4 || teste2)){
        for(int i=0, j=1; i<=4 && j<=5; i+=2, j+=2){
            Tabuleiro[posicao[i]] [posicao[j]] = 3;
        } 
    }else{
        printf("entrada nao valida\n");
    }
}

void habilidadeCone(int origem[2], int Tabuleiro[10][10]){

    //if para quando a habilidade for lançada, mas não houver a continuação
    if(origem[0] > 9 || origem[1] > 9){
        printf("não existe essa posicao no tabuleiro");
    }else{
        //definindo a origem no tabuleiro
        Tabuleiro[origem[0]][origem[1]] = 5;
        
        // definindo o abaixo da origem
        Tabuleiro[origem[0] + 1][origem[1]] = 5;
        Tabuleiro[origem[0] + 1][origem[1] -1] = 5;
        Tabuleiro[origem[0] + 1][origem[1] +1] = 5;

        Tabuleiro[origem[0] + 2][origem[1]] = 5;
        Tabuleiro[origem[0] + 2][origem[1] -1] = 5;
        Tabuleiro[origem[0] + 2][origem[1] -2] = 5;
        Tabuleiro[origem[0] + 2][origem[1] + 1] = 5;
        Tabuleiro[origem[0] + 2][origem[1] + 2] = 5;
    }
    

    


}

void habilidadeCruz(int origem[2], int Tabuleiro[10][10]){ 

    if(origem[0]>9 || origem[1]>9){
        printf("não existe essa posicao no tabuleiro");
    }else{
        //definindo a origem no tabuleiro
        Tabuleiro[origem[0]][origem[1]] = 5;
        
        // definindo abaixo e acima da origem
        Tabuleiro[origem[0] + 1][origem[1]] = 5;
        Tabuleiro[origem[0] - 1][origem[1]] = 5;

        //definindo esquerda e direita
        Tabuleiro[origem[0]][origem[1] - 1] = 5;
        Tabuleiro[origem[0]][origem[1] + 1] = 5;
        
    }
}

void habilidadeOctaedro(int origem[2], int Tabuleiro[10][10]){
    
    if(origem[0]>9 || origem[1]>9){
        printf("não existe essa posicao no tabuleiro");
    }else{
        Tabuleiro[origem[0]][origem[1]] = 5;
        //mesma coluna da origem
        Tabuleiro[origem[0] + 1][origem[1]] = 5;
        Tabuleiro[origem[0] + 2][origem[1]] = 5;
        Tabuleiro[origem[0] - 1][origem[1]] = 5;
        Tabuleiro[origem[0] - 2][origem[1]] = 5;
        //mesma linha
        Tabuleiro[origem[0]][origem[1]-1] = 5;
        Tabuleiro[origem[0]][origem[1]-2] = 5;
        Tabuleiro[origem[0]][origem[1]+1] = 5;
        Tabuleiro[origem[0]][origem[1]+2] = 5;
        //pontas
        Tabuleiro[origem[0]+1][origem[1]+1] = 5;
        Tabuleiro[origem[0]-1][origem[1]-1] = 5;
        Tabuleiro[origem[0]-1][origem[1]+1] = 5;
        Tabuleiro[origem[0]+1][origem[1]-1] = 5;



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
    int navioHorizontal1[6] = {0,1,0,2,0,3};
    NavioNaHorizontal(navioHorizontal1, Tabuleiro);

    // Array com posição do navio vertical
    // intercalando em x,y,x,y,x,y
    int navioVertical[6] = {6,3,7,3,8,3};
    NavioNaVertical(navioVertical, Tabuleiro);

    // Array com posição do navio diagonal
    // intercalando em x,y,x,y,x,y
    //Primeiro navio na diagonal
    int navioDiagonal[6] = {1,1,2,2,3,3};
    NavioNaDiagonal(navioDiagonal, Tabuleiro);

    //Segundo navio na diagonal
    int navioDiagonal2[6] = {9,4,8,5,7,6};
    NavioNaDiagonal(navioDiagonal2, Tabuleiro);
    
    // habilidade cone
    int origemCone[2] = {9,9}; 
    habilidadeCone(origemCone, Tabuleiro);

    //habilidade Cruz
    int origemCruz[2] = {5,5}; 
    habilidadeCruz(origemCruz, Tabuleiro);

    int origemOctaedro[2] = {5,5}; 
    habilidadeOctaedro(origemOctaedro, Tabuleiro);


    //enviando o tabuleiro em forma de texto para o terminal
    //linha
    for(int i=0; i<=9; i++){
        //coluna
        for(int j=0; j<=9; j++){
            if(Tabuleiro[i][j]==0){
                printf("\033[1;36m%d\033[0m", Tabuleiro[i][j]);
            }
            else if(Tabuleiro[i][j]==3){
                printf("\033[1;32m%d\033[0m", Tabuleiro[i][j]);
            }
            else if(Tabuleiro[i][j]==5){
                printf("\033[1;31m%d\033[1;31m", Tabuleiro[i][j]);
            }
            if(j==9){
                printf("\n");
                break;
            }
        }
    }

    return 0;

}