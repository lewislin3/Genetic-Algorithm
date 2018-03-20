#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "define.h"

int main() {
    struct population *ptr,*newptr;
    int i,j;
    int max[gens]={0};
    srand(time(NULL));
    ptr=malloc(p_size*sizeof(struct population));
    newptr=malloc(p_size*sizeof(struct population));
    for (i=0; i!=p_size; i++) {
        for (j=0; j!=g_size; j++) {
            ptr[i].gene[j]=rand()%2;
        }
    }
    fitness(ptr);
    showpopulation(ptr);
    for (i=0; i!=gens; i++) {
        generation(ptr,newptr);
        max[i]=ptr[0].fitness;
        printf("%d\n",ptr[5].fitness);
    }
    for (i=0; i!=gens; i++) {
        printf("gen%d : %d\n",i,max[i]);
    }
    return 0;
    
    
}
