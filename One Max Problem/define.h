#ifndef Header_h
#define Header_h
#include <stdio.h>

#define p_size 200
#define g_size 50
#define c_rate 1
#define m_rate 0
#define gens 100

struct population{
    int gene[g_size];
    int fitness;
};

void showpopulation(struct population*);
int func(int);
void mutation(struct population*);
void crossover(struct population*);
void fitness(struct population*);
void generation(struct population*,struct population*);
int randomnumber(void);


#endif /* Header_h */
