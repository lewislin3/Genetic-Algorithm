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
                if(ptr[i].gene[j]==0){ptr[i].gene[j]=1;}
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
    int sum_fit=0;
    int i,j;
    int wheel1,wheel2;
    
    for (i=0; i!=p_size; i++) {
        sum_fit=sum_fit+ptr[i].fitness;
    }
    for (i=0; i!=p_size; i=i+2) {
        w1=ptr[p_size-1];
        w2=ptr[p_size-1];
        wheel1=rand()%sum_fit;
        wheel2=rand()%sum_fit;
        for (j=0; j!=p_size; j++) {
            if(wheel1>ptr[j].fitness){wheel1=wheel1-ptr[j].fitness;}
            else{
                w1=ptr[j];
                break;
            }
        }
        for (j=0; j!=p_size; j++) {
            if(wheel2>ptr[j].fitness){wheel2=wheel2-ptr[j].fitness;}
            else{
                w2=ptr[j];
                break;
            }
        }
        newptr[i]=w1;
        newptr[i+1]=w2;
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


