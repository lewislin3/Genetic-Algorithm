#ifndef Header_h
#define Header_h
#include <stdio.h>

#define p_size 1
#define g_size 10
#define c_rate 1
#define m_rate 0
#define gens 100

struct population{
    double gene[g_size];
    long double fitness;
};

double gauss(double std);
void showpopulation(struct population*);
int func(int);
void mutation(struct population*, struct population*, double std_v);
void crossover(struct population*);
void fitness(struct population*);
void generation(struct population*,struct population*);


#endif /* Header_h */
