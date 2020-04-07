#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int fil =15, col,i,j;
    srand(time(NULL));
    col = rand() %16;

    int mt[fil][col];

    for ( i = 0; i < col; i++){
        for(j=0;j<fil;j++){
            mt[i][j] =100+rand() % (1000 - 100);
            printf("|%d|", mt[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
