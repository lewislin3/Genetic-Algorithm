#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



double gauss(double std){
    
    
    double u = (double)rand()  / RAND_MAX;
    double v = (double)rand() / RAND_MAX ;
    double x = sqrt(-2 * log(u)) * cos(2 * M_PI * v) * std ;
    //printf("%f\n",x);
    return x;
}

void showpopulation(struct population *ptr){

    int i,j;
    for(i=0; i!=p_size; i++){
        /*for(j=0; j!=g_size; j++){
            printf("%f ",ptr[i].gene[j]);
        }*/
        printf("[%f]",ptr[i].fitness);
    }
    printf("\n");
}

void mutation(struct population *new, struct population *old){

    int i,j;
    for(i=0; i!=p_size; i++){
        for(j=0; j!=g_size; j++){
            old[i].gene[j]=new[i].gene[j];
            new[i].gene[j]+=sigma()*gauss(1);
        }
        fitness(new);
        fitness(old);
        if(new[i].fitness>old[i].fitness){
            for(j=0; j!=g_size; j++){
                new[i].gene[j]=old[i].gene[j];
            }
        }
        fitness(new);
        fitness(old);
        
    }
    
    
}

double sigma(void){
    double ans;
    ans=std_v*pow(e,tou*gauss(1));
    //printf("[%d]\n",ans);
    return ans;
}

/// fitness are functions that changes with the scenario

void fitness(struct population *ptr){

    int i,j;
    for(i=0; i!=p_size; i++){
        ptr[i].fitness=0;
        for(j=0; j!=g_size; j++){
            ptr[i].fitness+=(ptr[i].gene[j])*(ptr[i].gene[j]);
        }
    }

}


