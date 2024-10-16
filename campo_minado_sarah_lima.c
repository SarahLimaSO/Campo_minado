#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Escolhe nivel do jogo
void gameLevel(int *lin, int *col){
    char level[8];

    while(1){
        scanf("%s", level);

        if((strcmp(level,"facil")) == 0){
            *lin = 10;
            *col = 10;
           // printf("deu certo");
            break;
        }
        else if((strcmp(level,"medio")) == 0){
            *lin = 20;
            *col = 20;
            break;
        }
        else if((strcmp(level,"dificil")) == 0){
            *lin = 30;
            *col = 30;
            break;
        }
        else{
            printf("ERROR! level not found =( \nPlease, enter a valid level!!!\n\n");
        }
    }
}
//Creating a new matrix
char** newMatrix(int lin, int col){
    char **mat = calloc(lin,sizeof(char*));

    if(mat == NULL){
        printf("ERROR01! Insufficient memory!");
        exit(1);
    }

    for(int ind = 0; ind < lin; ind++){
        mat[ind] = (char*) calloc(col,sizeof(char));

        if(mat == NULL){
        printf("ERROR02! Insufficient memory!");
            exit(1);
        }
    }
    return mat;
}

//Initializing the matrix mat
char** initializeMat(char** mat, int nLin, int nCol){

    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            mat[line][column] = 'x';
        }
    }
    return mat;
} 
void printMatrix(char** mat, int nLin, int nCol){
    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            printf("%c",mat[line][column]);
        }
        putchar('\n');
    }
}
int main() {
    int lin;
    int col;

    gameLevel(&lin, &col);
    char ** mat = newMatrix(lin,col);
   
    
//We call the funcion "initializeMatrix" to initializate the matrix mat
    initializeMat(mat, lin, col);

//Printing the matrix
    printMatrix(mat, lin, col);

    return 0;
}
