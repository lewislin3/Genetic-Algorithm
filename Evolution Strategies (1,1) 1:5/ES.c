#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    srand(time(NULL));

    struct population *new,*old;
    int i,j;
    double std_v=0.1;
    int success=0;


    new=malloc(p_size*sizeof(struct population));
    old=malloc(p_size*sizeof(struct population));
    for (i=0; i!=p_size; i++){
        for (j=0; j!=g_size; j++){
            new[i].gene[j]=1;
        }
    }

    for (i=0; i!=1000000; i++){
        success=0;
        for (j=0; j!=10;j++){
            printf("%d\n",i*100+j);
            mutation(new,old,std_v);
            fitness(new);
            fitness(old);
            if (new[0].fitness<=old[0].fitness){
                success++;
            }
            printf("[%f]\n",std_v);
            printf("NEW:");
            showpopulation(new);
            printf("OLD:");
            showpopulation(old);
            if(new[0].fitness<=0.005){return 0;}

        }

        
        if (((double)success/10)>0.2){
            std_v=std_v/0.81;
        }
        if (((double)success/10)<0.2){
            std_v=std_v*0.81;
        }  
        
        
    

        
          
    }

    



    
   
    
    
    return 0;
}
