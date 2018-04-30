#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    srand(time(NULL));

    struct population *new,*old;
    int i,j,k;
    int success=0;

    double std_v=0.1;

    new=malloc(p_size*sizeof(struct population));
    old=malloc(p_size*sizeof(struct population));
    for (i=0; i!=p_size; i++){
        for (j=0; j!=g_size; j++){
            new[i].gene[j]=1;
        }
    }

    for (i=0; i!=100000; i++){
        success=0;
        for (k=0; k!=100; k++){
            printf("%d\n",i*100+k);
            mutation(new,old,std_v);
            fitness(new);
            fitness(old);

            if (new[0].fitness<=old[0].fitness){
                success++;
            }

            printf("NEW:");
            showpopulation(new);
            printf("OLD:");
            showpopulation(old);
            
            if(new[0].fitness>old[0].fitness){
                for(j=0; j!=g_size; j++){
                    new[0].gene[j]=old[0].gene[j];
                }
            }
               
            fitness(new);
            fitness(old);
            printf("{%f}\n",std_v);
            if(new[0].fitness<=0.005){return 0;}

        }
        if ((double)success/100>0.2){
            std_v=std_v/0.82;
        }
        if ((double)success/100<0.2){
            std_v=std_v*0.82;
         }

        
    }

    



    
   
    
    
    return 0;
}
