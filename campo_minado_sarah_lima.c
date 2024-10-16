#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Escolhe nivel do jogo
void gameLevel(int *lin, int *col, int* plays){
    char level[8];
    int plays;

    while(1){
        scanf("%s", level);

        if((strcmp(level,"facil")) == 0){
            *lin = 10;
            *col = 10;
            plays = (*lin * (*col))-1;
            printf("deu certo %d\n", plays);
            break;
        }
        else if((strcmp(level,"medio")) == 0){
            *lin = 20;
            *col = 20;
            plays = (*lin * (*col))-1;
            printf("deu certo %d\n", plays);
            break;
        }
        else if((strcmp(level,"dificil")) == 0){
            *lin = 30;
            *col = 30;
            plays = (*lin * (*col))-1;
            printf("deu certo %d\n", plays);
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
    srand(time(NULL));

    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            mat[line][column] = 'x';
        }
    }
    return mat;
} 
//Priting the matrix
void printMatrix(char** mat, int nLin, int nCol, int coordX, int coordY){
    
    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            if((x != line)&&(y != column)){
                
                printf("%c",mat[line][column]);
            }
            else{

            }
        }
        putchar('\n');
    }
}  
int main() {
    int lin, col, coordX, coordY, plays;

//Choosing the game level
    gameLevel(&lin, &col, &plays);
    char ** mat = newMatrix(lin,col);
   
    
//We call the funcion "initializeMatrix" to initializate the matrix mat
    initializeMat(mat, lin, col);

//Printing the matrix
    printMatrix(mat, lin, col, coordX, coordY);

    free(mat);
    return 0;
}
