#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando nova matriz
char** newMatrix(int lin, int col){
    char **mat = calloc(lin,sizeof(char*));

    for(int ind = 0; ind < lin; ind++){
        mat[ind] = (char*) calloc(col,sizeof(char));
    }
    
    return mat;
}

//Inicializando matriz
char** initializeMat(char** mat){

    return mat;
} 
//Escolhe nivel do jogo
void gameLevel(){
    char level[8];
    scanf("%s", level);

    if((strcmp(level),"facil") == 0){
        newMatrix(10,10);
    }
    else if((strcmp(level),"medio") = 0){
        newMatrix(20,20);
    }
    else if((strcmp(level),"dificil") = 0){
        newMatrix(30,30);
    }
    else{
        printf("Level not found =( \n Please, enter a valid level!!!")
    }
}
int main() {
   

    return 0;
}
