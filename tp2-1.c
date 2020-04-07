#include<stdio.h>
#include<stdlib.h>
#define N 4
#define M 5

int main (){
	int f,c;	
	double mt[N][M];
		
    for(f = 0;f<N; f++) {
        for(c = 0;c<N; c++){
            printf("|%lf|", mt[f][c]);
            }
        printf("\n");
        }

    return 0;
}