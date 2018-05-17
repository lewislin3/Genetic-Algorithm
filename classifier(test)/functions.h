//
//  functions.h
//  classifier
//
//  Created by lewis0816 on 2018/5/15.
//  Copyright © 2018年 lewis0816. All rights reserved.
//

#ifndef functions_h
#define functions_h

#define p_size 50
#define action_num 2
#define maxfit 10000000


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct populations{
  
    int rules[6];
    int action;
    double fitness;
    int match_time;
    int correct;
    int error;
    int m_set;
    int c_t;
    int e_t;
    
};

bool match(int [6],int [6]);
void createpopulation(struct populations*, int, int [6]);
int getanwser(int [6]);
void showrules(struct populations*, int);
void mutation(struct populations*, int,int);
void checksame(struct populations*, int);
void checksame2(struct populations*, int);
#endif /* functions_h */
