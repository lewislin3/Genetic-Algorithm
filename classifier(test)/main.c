#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>

int main() {
    
    int input[6];
    int i,j;
    int p_exist=0;
    int p_match;
    int tmp,catch;
    int action_cnt[action_num];
    int ans;
    int runtime=0;
    int test=0;
    int subruntime=0;
    int correcttime=0;
    int select2;
    
    struct populations *pop;
    
    pop=malloc(sizeof(struct populations)*p_size);
    srand(time(NULL));
    
    
    while(1){
        runtime++;
        subruntime++;
        
        //printf("input\n");
        for (i=0; i!=6; i++) {
            input[i]=rand()%2;
        }
        
        p_match=0;
        for (i=0; i!=action_num; i++) {
            action_cnt[i]=0;
        }
        for (i=0; i!=p_exist; i++) {
            if(match(pop[i].rules, input)){
                p_match=1;
                pop[i].m_set=1;
                pop[i].match_time++;
                action_cnt[pop[i].action]+=pop[i].fitness;
            }
        }
        //printf("p_match:%d\n",p_match);
        
        if (p_match==0) {
            if (p_exist<p_size) {
                createpopulation(pop, p_exist, input);
                p_exist++;
                //printf("p_exist:%d\n",p_exist);
            }
            else{
                
                tmp=pop[0].fitness;
                catch=0;
                for (i=0; i!=p_size; i++) {
                    if (pop[i].fitness<tmp) {
                        tmp=pop[i].fitness;
                        catch=i;
                    }
                }
                createpopulation(pop, catch, input);
                createpopulation(pop, catch, input);
            }
            catch=rand()%action_num;
            ans=getanwser(input);
            if (ans==catch) {
                //printf("right\n");
                correcttime++;
            }

            
        }
        else{
            test++;
            
            tmp=action_cnt[0];
            catch=0;
            for (i=0; i!=action_num; i++) {
                if (action_cnt[i]>tmp) {
                    tmp=action_cnt[i];
                    catch=i;
                }
            }
            //printf("input:");
            for (i=0; i!=6; i++) {
                //printf("%d",input[i]);
            }
            //printf("\n");
            //printf("output:%d\n",catch);
            ans=getanwser(input);
            if (ans==catch) {
                //printf("right\n");
                correcttime++;
            }
            else{
                //printf("wrong\n");
            }
            for (i=0; i!=p_exist; i++) {
                if (pop[i].m_set) {
                    //printf("[%d %d %d]\n",pop[i].correct,pop[i].error,pop[i].match_time);
                    if (pop[i].action==ans) {
                        pop[i].correct++;
                        pop[i].c_t++;
                        pop[i].fitness=pop[i].fitness*(1+(double)(pop[i].correct/pop[i].match_time));
                        
                        if (pop[i].fitness>=maxfit) {
                            pop[i].fitness=maxfit;
                        }
                    }
                    else{
                        pop[i].error++;
                        pop[i].e_t++;
                        pop[i].fitness=pop[i].fitness/(1+(double)(pop[i].error/pop[i].match_time));
                        if (pop[i].fitness<=0) {
                            pop[i].fitness=0.5;
                        }
                        
                    }
                    
                    if (pop[i].match_time==6){
                        pop[i].match_time=0;
                        pop[i].correct=0;
                        pop[i].error=0;
                    }
                }
            }
            
            
        }
        
        
        //showrules(pop, p_exist);
        if (p_exist>=20) {
            for (j=0; j!=2; j++) {
                select2=0;
                tmp=pop[0].fitness;
                for (i=0; i!=p_exist; i++) {
                    if (tmp>=pop[i].fitness) {
                        tmp=pop[i].fitness;
                        select2=i;
                    }
                }
                if (p_exist<=p_size) {
                    mutation(pop,p_exist,p_exist);
                    p_exist++;
                    checksame(pop, p_exist);
                    //checksame2(pop, p_exist);
                }
                else{
                    mutation(pop,p_exist,select2);
                    checksame(pop, p_exist);
                    //checksame2(pop, p_exist);
                }
                
                
                
            }
            
        }
        for (i=0; i!=p_exist; i++) {
            pop[i].m_set=0;
        }

        
        
        
        
        if(subruntime==100){
            printf("%f\n",(double)correcttime/subruntime);
            correcttime=0;
            subruntime=0;
        }
        
        if (runtime==10000) {
            showrules(pop, p_exist);
            printf("%f\n",(double)test/runtime);
            return 0;
        }
        
        
    }
    
    
    
    
    return 0;
}
