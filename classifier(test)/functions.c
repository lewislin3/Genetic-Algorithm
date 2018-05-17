//
//  functions.c
//  classifier
//
//  Created by lewis0816 on 2018/5/15.
//  Copyright © 2018年 lewis0816. All rights reserved.
//

#include "functions.h"
#include <stdbool.h>

bool match(int rules[6],int input[6]){
    int i=0;
    for (i=0; i!=6; i++) {
        if (rules[i]!=input[i] && rules[i]!=2) {
            return 0;
        }
    }
    return 1;
}
void createpopulation(struct populations* pop, int place, int input[6]){
    
    int i=0;
    for (i=0; i!=6; i++) {
        if (rand()%6==0) {
            pop[place].rules[i]=2;
        }
        else{
            pop[place].rules[i]=input[i];
        }
    }
    
    pop[place].action=rand()%action_num;
    
    pop[place].fitness=1;
    pop[place].match_time=0;
    pop[place].correct=0;
    pop[place].error=0;
    pop[place].m_set=0;
    pop[place].c_t=0;
    pop[place].e_t=0;
    
}

int getanwser(int input[6]){
    
    int ans=0;
    
    
    if (input[4]==0 && input[5]==0) {
        ans=input[0];
    }
    if (input[4]==0 && input[5]==1) {
        ans=input[1];
    }
    if (input[4]==1 && input[5]==0) {
        ans=input[2];
    }
    if (input[4]==1 && input[5]==1) {
        ans=input[3];
    }
    
    
    
    /*
     if (input[0]==0) {
        ans=0;
     }
     else {
        ans=1;
     }
     */


    /*
    if (input[0]==0 &&input[1]==0 &&input[2]==0 &&input[3]==0 &&input[4]==0 &&input[5]==0 ) {
        ans=2;
    }
    else if (input[0]==0) {
        ans=0;
    }
    else {
        ans=1;
    }
    */
    
    /*
    if (input[0]==0 &&input[1]==0 &&input[2]==0 &&input[3]==0 &&input[4]==0 &&input[5]==0 ) {
        ans=2;
    }
    else if (input[0]==1 &&input[1]==1 &&input[2]==1 &&input[3]==1 &&input[4]==1 &&input[5]==1 ) {
        ans=3;
    }
    else if (input[0]==0) {
        ans=0;
    }
    else {
        ans=1;
    }
    */
    
    return ans;
}

void showrules(struct populations* pop, int p_exist){
    int i,j;
    for (i=0; i!=p_exist; i++) {
        for (j=0; j!=6; j++) {
            printf("%d",pop[i].rules[j]);
        }
        printf(" %d %f %d %d\n",pop[i].action,pop[i].fitness,pop[i].c_t,pop[i].e_t);
    }
    
}

void mutation(struct populations* pop, int p_exist, int select2){
    int fitsum=0;
    int i;
    int random=0;
    int select1=0;
    
    for (i=0; i!=p_exist; i++) {
        fitsum+=pop[i].fitness;
    }
    random=rand()%fitsum;
    
    for (i=0; i!=p_exist; i++) {
        if (fitsum>=0) {
            fitsum-=pop[i].fitness;
            select1=i;
        }
    }
    
    
    pop[select2].action=rand()%action_num;
    pop[select2].correct=0;
    pop[select2].error=0;
    pop[select2].fitness=pop[select1].fitness;
    pop[select2].m_set=0;
    pop[select2].match_time=0;
    pop[select2].c_t=0;
    pop[select2].e_t=0;
    for (i=0; i!=6; i++) {
        if (rand()%3==0) {
                pop[select2].rules[i]=rand()%3;
        }
        else{
            pop[select2].rules[i]=pop[select1].rules[i];
        }
    }
}

void checksame(struct populations* pop, int p_exist){
    int i,j;
    int p_exist2=p_exist;
    for (i=0; i!=p_exist2-1; i++) {
        for (j=0; j!=6; j++) {
            if (pop[i].rules[j]!=pop[p_exist2-1].rules[j]&&pop[i].rules[j]!=2) {
                break;
            }
        }
        if (j==6 && pop[p_exist-1].action==pop[i].action) {
            pop[p_exist-1].action=pop[i].action;
            pop[p_exist-1].correct=pop[i].correct;
            pop[p_exist-1].error=pop[i].error;
            //pop[p_exist-1].fitness=pop[i].fitness;
            pop[p_exist-1].m_set=pop[i].m_set;
            pop[p_exist-1].match_time=pop[i].match_time;
            pop[p_exist-1].c_t=0;
            pop[p_exist-1].e_t=0;
            for (j=0; j!=6; j++) {
                pop[p_exist2-1].rules[j]=pop[i].rules[j];
            }
            
        }
    }
}

void checksame2(struct populations* pop, int p_exist){
    int i,j;
    for (i=0; i!=p_exist-1; i++) {
        for (j=0; j!=6; j++) {
            if (pop[i].rules[j]!=pop[p_exist-1].rules[j]&&pop[p_exist].rules[j]!=2) {
                break;
            }
        }
        if (j==6 && pop[p_exist-1].action==pop[i].action) {
            pop[i].action=pop[p_exist-1].action;
            pop[i].correct=pop[p_exist-1].correct;
            pop[i].error=pop[p_exist-1].error;
            //pop[i].fitness=pop[p_exist-1].fitness;
            pop[i].m_set=pop[p_exist-1].m_set;
            pop[i].match_time=pop[p_exist-1].match_time;
            pop[p_exist-1].c_t=0;
            pop[p_exist-1].e_t=0;
            for (j=0; j!=6; j++) {
                pop[i].rules[j]=pop[p_exist-1].rules[j];
            }
            
        }
    }
}
