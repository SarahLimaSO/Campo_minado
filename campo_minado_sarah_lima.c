#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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
           // printf("deu certo facil%d\n", *plays);
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
            *plays = (*lin * (*col)) - (*nMines);
            printf("deu certo dificil%d\n", *plays);
            break;
        }
        else{
            printf("ERROR! level not found =( \nPlease, enter a valid level!!!\n\n");
        }
    }
}

//Creating a new matrix
char** newMatrix(int nLin, int nCol){
    char **mat = calloc(nLin,sizeof(char*));

    if(mat == NULL){
        printf("ERROR01! Insufficient memory!");
        exit(1);
    }

    for(int ind = 0; ind < nLin; ind++){
        mat[ind] = (char*) calloc(nCol,sizeof(char));

        if(mat == NULL){
        printf("ERROR02! Insufficient memory!");
            exit(1);
        }
    }
    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            mat[line][column] = 'x';
        }
    }
    return mat;
}

//Creating a matrix that is initializated with the coordinate of the mines
int* createMines(int nLin, int nCol, int nMines){
    int randNum, cont, line, column;
    int coord[2];
    int *mines = calloc(nLin*nCol,sizeof(int));
    cont = 0;
    
    //Inicializating the seed with time
    srand(time(NULL));

    //Modifying the copy mines with "-1", which means that the designated coordinate has a mine
    while(cont < nMines){
        int element;

        //The valor of "coord" will be a number beetween 0 and the number of lines(because the number of lines is equal to the number of columns)
        for(int indV = 0; indV < 2; indV++){ 
            randNum = rand() %((nLin - 1));
            // printf("%d\n", randNum);
            coord[indV] = randNum;
        }
        line = coord[0];
        column = coord[1];

        element = mines[line*nCol+column];
       
        if(element != -1){
            mines[line*nCol+column] = -1;
            cont++;
        }
    }

    return mines;
}

//Modifies the matrix mat according wih the coordinates that were chosen by the player
char** modifyMat(char** mat, int nLin, int nCol, int coordX, int coordY, int minesProx){
    //Converts the int minesProx to the correspondent char
    char converted = '0' + minesProx;

    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            if((coordX == line)&&(coordY == column)){
                mat[line][column] = converted;
            }
        }
    }
    return mat;
} 

//Priting the matrix
void printMatrix(char** mat, int nLin, int nCol){
    
    for(int line = 0; line < nLin; line++){
        for(int column = 0; column < nCol; column++){
            printf("%c ",mat[line][column]);  
        }
        putchar('\n');
    }
}

//Calculates the number of mines within a distance of at least one 
int minesProx(int* mines, int nLin, int nCol, int coordX, int coordY){
    int qntdMines;
    qntdMines = 0;

    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            int dist = 0;

            dist = sqrt(pow((i-coordX), 2) + pow((j-coordY),2));
            if((mines[i*nCol+j] == -1)&&(dist == 1)){
                qntdMines++;
            }
        }
    }

    //Returns the number of mines near the coordinate chosen by the player
    return qntdMines;
}

//Modify the template according to the number of nearby mines
int* finalTemplate(int *mines, int nLin, int nCol, int nMines){
    int qntdMines;
    qntdMines = 0;

    //Matrix that stores the coordinates of the mines
    //int coordMines[nMines*2];
    
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){

           //If we find the mine... we add plus 1 to the value of the near positions
            if(mines[i*nCol+j] == -1){
                for(int x = i-1; x <= i+1; x++){

                    for(int y = j-1; y <= j+1; y++){
                        if(mines[x*nCol+y]!= -1){
                            if((x<nLin)&&(y<nCol)&&(x>=0)&&(y>=0)){
                                mines[x*nCol+y]++;
                            }
                        }
                    }
                }
            } 
        }
    } 
}
void printTemplate(int *mines, int nLin, int nCol){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            printf("%d ",mines[i*nCol+j]);  
        }
        putchar('\n');
    }
    putchar('\n');
    putchar('\n');
} 

//If the player hits a mine, it prints game over. But if the number of moves runs out and he hasn't hit a mine, he wins.
int gameOver(int* mines, int plays, int coordX, int coordY, int nCol){
    if(mines[coordX*nCol+coordY] == -1){
        return 1;
    }
    return 0;
} 

int main() {
    int lin, col, coordX, coordY, plays, nMines;

//Start of the game
printf("\n\n---------------- Bem-vind@ ao minefield game!! ----------------\n\n");
//Choosing the game level
    printf("Escolha o nível do jogo:\n\n");
    printf("-Digite \"facil\" para o nível fácil;\n");
    printf("-Digite \"medio\" para o nível médio;\n");
    printf("-Digite \"dificil\" para o nível difícil;\n\n");
    gameLevel(&lin, &col, &plays, &nMines);
   
//We call the funcion "newMatrix" to create and initializate the matrix mat
    char ** mat = newMatrix(lin,col);

//Inicilizating a copy of the matrix mat acoording with the coodinated generated by the random
    int* mines = createMines(lin,col,nMines);

//
    while(plays >= 0){
        int qntdMines = 0;

        putchar('\n');
        for(int k = 0; k < 65; k++){
            putchar('-');
        }
        putchar('\n');
        putchar('\n');

       //Printing the matrix
        printMatrix(mat, lin, col);

        putchar('\n');
        for(int k = 0; k < 65; k++){
            putchar('-');
        }
        putchar('\n');
        
        printf("Digite uma coordenada no formato (x,y) que esteja entre 1 e %d:\n", lin);
        

        //Read the coordinates chosen by the player
        scanf("%d,%d", &coordX, &coordY);

        //Subtract minus 1 from the value of the coordinates
        coordX -= 1;
        coordY -= 1;
        qntdMines = minesProx(mines, lin, col, coordX, coordY);

        //Modifies the matrix mat according wih the coordinates that were chosen by the player
        modifyMat(mat, lin, col, coordX, coordY, qntdMines);

        //If the funcion game over return 1, the player lost, and the loop stops 
        int gameStatus = gameOver(mines, plays, coordX, coordY,col);

        if(gameStatus){
            printf("\ngame over :(\n");

            //Print the matrix template
            finalTemplate(mines,lin,col,nMines);
            //finalTemplate2(mines,lin,col,nMines);
            printTemplate(mines,lin,col);
            break;
        }
        else if((plays == 0)){
            printf("parabéns, vc eh fera :)\n");
            //Print the matrix template
            finalTemplate(mines,lin,col,nMines);
            printTemplate(mines,lin,col);
        }
        
        plays--;
    }

    free(mat);
    free(mines);
    return 0;
}
