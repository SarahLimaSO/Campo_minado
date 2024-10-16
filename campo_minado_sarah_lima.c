#include <stdio.h>

int newMatrix(int lin, int col){
    char mat = calloc(lin*sizeof(char));
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
