#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    srand(time(NULL));

    struct population *new,*old;
    int i,j;
    long double std_v=0.01;
    int success=0;


    new=malloc(p_size*sizeof(struct population));
    old=malloc(p_size*sizeof(struct population));
    for (i=0; i!=p_size; i++){
        for (j=0; j!=g_size; j++){
            new[i].gene[j]=1;
        }
    }

    for (i=0; i!=10000000; i++){

        printf("%d\n",i);
        mutation(new,old,std_v);
        fitness(new);
        fitness(old);
        if (new[0].fitness<=old[0].fitness){
            success++;
        }
        printf("[[%f]]\n",(double)success/i);
        if (((double)success/i)>0.2){
            std_v=std_v/0.82;
        }
        if (((double)success/i)<0.2){
            std_v=std_v*0.82;
        }
        printf("NEW:");
        showpopulation(new);
        printf("OLD:");
        showpopulation(old);
        printf("[%d]\n\n",success);
        if(new[0].fitness<=0.005)break;
    }

    



    
   
    
    
    return 0;
}
