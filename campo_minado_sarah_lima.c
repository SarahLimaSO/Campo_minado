#include <stdio.h>

//Criando nova matriz
int newMatrix(int lin, int col){
    char **mat = calloc(lin*sizeof(char*));

    for(int ind = 0; ind < lin; ind++){
        mat[ind](char*)= calloc(n*sizeof(char));
    }
    
    return mat;
}
int main() {
   char level[7];

   scanf("%s", level);

   switch(level){
        case "facil":
            newMatrix(10,10);
        break;

        case "medio":
            newMatrix(20,20);
        break;

        case "dificil":
            newMatrix(30,30);
        break;

    }
    return 0;
}
