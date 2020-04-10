#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int fil =15, col,i,j;
    int contPar=0, contImp=0, contImpd=0,contPard=0;
    int *vec;
    srand(time(NULL));
    col = rand() %16;

    int mt[fil][col];

	vec = (int*)malloc(15*sizeof(int));
    if (vec == NULL){
        printf("espacio insuficiente");
    }

    for ( i = 0; i < fil; i++){
        for(j=0;j<col;j++){
            mt[i][j] =100+rand() % (1000 - 100);
            if ( mt[i][j]%2==0) {
                contPar++;
            }
            else{
                contImp++;
            }
            
            
            printf("|%d|", mt[i][j]);
        }
        printf("\n");
    }

    printf("\n\n numeros pares= %d\n numeros impares= %d", contPar,contImp);
    
    
    
    printf("\n\n");
    for ( i = 0; i < 15; i++){
            vec[i] =100+rand() % (1000 - 100);
            if ( vec[i]%2==0) {
                contPard++;
            }
            else{
                contImpd++;
            }
            printf("|%d|", vec[i]);
    }
	printf("\n\n numeros pares= %d\n numeros impares= %d\n", contPard,contImpd);

    system("pause");
    return 0;
}
