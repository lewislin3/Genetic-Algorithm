#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

int main() {
    struct population *ptr,*newptr;
    int i,j,k;
    int max[10][gens]={0};
    int average[gens]={0};
    srand(time(NULL));
    ptr=malloc(p_size*sizeof(struct population));
    newptr=malloc(p_size*sizeof(struct population));
    
    for (k=0; k!=10; k++) {
        for (i=0; i!=p_size; i++) {
            for (j=0; j!=g_size; j++) {
                ptr[i].gene[j]=rand()%2;
            }
        }
        fitness(ptr);
        showpopulation(ptr);
        for (i=0; i!=gens; i++) {
            printf("%d\n",i);
            generation(ptr,newptr);
            max[k][i]=ptr[0].fitness;
        }
    }
    
    for (i=0; i!=gens; i++) {
        printf("gen%d : ",i);
        for (j=0; j!=10; j++) {
            printf("%d ",max[j][i]);
            average[i]=average[i]+max[j][i];
        }
        printf("\n");
    }
    for (i=0; i!=gens; i++) {
        printf("%d\n",(average[i]/10));
    }
    return 0;
}

