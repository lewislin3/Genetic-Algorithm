#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int gauss(double std){
    
    
    double u = (double)rand()  / RAND_MAX;
    double v = (double)rand() / RAND_MAX ;
    double x = sqrt(-2 * log(u)) * cos(2 * M_PI * v) * std ;
    printf("%f\n",x);
    return x;
}

void showpopulation(struct population *ptr){
    
}

void mutation(struct population *ptr){

    int i,j;
    for(i=0; i!=p_size; i++){
        for(j=0; j!=g_size; j++){
            ptr[i].gene[j]+=gauss(std_v);
        }
        
    }
    
}

void crossover(struct population *ptr){
    
}

void generation(struct population *ptr,struct population *newptr){
    
}

/// fitness are functions that changes with the scenario

void fitness(struct population *ptr){

}

