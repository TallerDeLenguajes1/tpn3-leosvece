#include<stdio.h>
#include<stdlib.h>
#define N 4
#define M 5

int main (){
	int f,c;	
	double mt[N][M], *p_mt;
    p_mt = &mt[0][0];

		
    for(f = 0;f<N; f++) {
        for(c = 0;c<N; c++){
            printf("|%lf|", p_mt);
            p_mt++;
            }
        printf("\n");
        }

    return 0;
}