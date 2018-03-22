#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomnumber(){
    srand(time(NULL));
    return rand();
}

void showpopulation(struct population *ptr){
    int i,j;
    struct population tmp;
    for (j=0; j!=p_size; j++) {
        for (i=1; i!=p_size; i++) {
            if(ptr[i].fitness>ptr[i-1].fitness){
                tmp=ptr[i];
                ptr[i]=ptr[i-1];
                ptr[i-1]=tmp;
            }
        }
    }
    for (i=0; i!=p_size; i++) {
        for (j=0; j!=g_size; j++) {
            printf("%d",ptr[i].gene[j]);
        }
        printf(" %d\n",ptr[i].fitness);
    }
    printf("///////////////////\n");
}

void mutation(struct population *ptr){
    int i,j;
    int random;
    for (i=0;i!=p_size ; i++) {
        for (j=0; j!=g_size; j++) {
            random=rand()%100+1;
            if (random<=(m_rate*100)) {
                if(ptr[i].gene[j]==1){ptr[i].gene[j]=0;}
                else{ptr[i].gene[j]=1;}
            }
        }
    }
}

void crossover(struct population *ptr){
    int i,j;
    int cut;
    int tmp=0;
    int random;
    for (i=0; i!=p_size; i=i+2) {
        cut=rand()%(g_size-1);
        random=rand()%100+1;
        if (random<=(c_rate*100)) {
            for (j=cut; j!=g_size; j++) {
                tmp=ptr[i].gene[j];
                ptr[i].gene[j]=ptr[i+1].gene[j];
                ptr[i+1].gene[j]=tmp;
            }
        }
    }
    mutation(ptr);
    fitness(ptr);
}

void generation(struct population *ptr,struct population *newptr){
    struct population w1,w2;
    int i,j;
    struct population select[tournament];
    
    for (j=0; j!=p_size; j=j+2) {
        for (i=0; i!=tournament; i++) {
            select[i]=ptr[rand()%p_size];
        }
        w1=select[0];
        for (i=0; i!=tournament; i++) {
            if (select[i].fitness>=w1.fitness) {
                w1=select[i];
            }
        }
        for (i=0; i!=tournament; i++) {
            select[i]=ptr[rand()%p_size];
        }
        w2=select[0];
        for (i=0; i!=tournament; i++) {
            if (select[i].fitness>=w2.fitness) {
                w2=select[i];
            }
        }
        newptr[j]=w1;
        newptr[j+1]=w2;
    }
    
    
    
    for (i=0; i!=p_size; i++) {
        ptr[i].fitness=newptr[i].fitness;
        for (j=0; j!=g_size; j++) {
            ptr[i].gene[j]=newptr[i].gene[j];
        }
    }
    crossover(ptr);
    showpopulation(ptr);
}

/// fitness are functions that changes with the scenario

void fitness(struct population *ptr){
    int i,j;
    for (i=0; i!=p_size; i++) {
        ptr[i].fitness=0;
        for (j=0; j!=g_size; j++) {
            ptr[i].fitness=ptr[i].fitness+ptr[i].gene[j];
        }
    }
}


