#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Escolhe nivel do jogo
void gameLevel(int *lin, int *col, int *plays, int *nMines ){
    char level[8];

    while(1){
        scanf("%s", level);

        if((strcmp(level,"facil")) == 0){
            *lin = 10;
            *col = 10;
            *nMines = 3;
            *plays = (*lin * (*col)) - (*nMines+1);
            printf("deu certo facil%d\n", *plays);
            break;
        }
        else if((strcmp(level,"medio")) == 0){
            *lin = 20;
            *col = 20;
            *nMines = 6;
            *plays = (*lin * (*col)) - (*nMines+1);
            printf("deu certo medio%d\n", *plays);
            break;
        }
        else if((strcmp(level,"dificil")) == 0){
            *lin = 30;
            *col = 30;
            *nMines = 9;
            *plays = (*lin * (*col)) - (*nMines+1);
            printf("deu certo dificil%d\n", *plays);
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
//Creating a matrix that is initializated with the coordinate of the mines
int** createMines(int nLin, int nMines){
    int coord, prevCoord;
    int **mines = malloc(2*sizeof(int));

    if(mines == NULL){
        printf("ERROR03! Insufficient memory!");
        exit(1);
    }

    for(int ind = 0; ind < 2; ind++){
        mines[ind] = malloc(nMines*sizeof(int));

        if(mines == NULL){
            printf("ERROR04! Insufficient memory!");
            exit(1);
        }
    }
    //Inicializating the seed with time
    srand(time(NULL));

    for(int lin = 0; lin < 2; lin++){
        for(int col = 0; col < nMines; col++){

            //The coord will be a number beetween 1 and the number of lines(because the number of lines is equal to the number of columns)
            coord = 1+ rand() %((nLin)+1);;

            if(coord != prevCoord){
                mines[lin][col] = coord;
                printf("coord %d\n", mines[lin][col]);
                prevCoord = coord;
            }
        }
        prevCoord = 0;
    }

    return mines;
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
//Priting the matrix
void printMatrix(char** mat, int nLin, int nCol, int coordX, int coordY){
    
    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            //if((x != line)&&(y != column)){

                printf("%c",mat[line][column]);
           // }
            //else{

            //}
        }
        putchar('\n');
    }
}  
int main() {
    int lin, col, coordX, coordY, plays, nMines;

//Choosing the game level
    gameLevel(&lin, &col, &plays, &nMines);
    char ** mat = newMatrix(lin,col);
   
    
//We call the funcion "initializeMatrix" to initializate the matrix mat
    initializeMat(mat, lin, col);

//Printing the matrix
    printMatrix(mat, lin, col, coordX, coordY);
    createMines(lin, nMines);

    free(mat);
    return 0;
}
