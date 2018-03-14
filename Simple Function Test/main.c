#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define c_rate 50
#define m_rate 10

struct population{
    int *gene;
    int fitness;
};

void showpopulation(struct population *ptr,int p_size,int g_size){
    
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

int func(int input){
    return input*input;
}

int btod(int* gene , int size){
    
    int i=0;
    int decimal=0;
    int two=1;
    
    for (i=0; i!=size; i++) {
        decimal=decimal+gene[i]*two;
        two=two*2;
    }
    return decimal;
}
void mutation(struct population *ptr,int p_size,int g_size){
    
    int i,j;
    for (i=0;i!=p_size ; i++) {
        for (j=0; j!=g_size; j++) {
            if (rand()%100<=m_rate) {
                if(ptr[i].gene[j]==1){
                    ptr[i].gene[j]=0;
                }
                if(ptr[i].gene[j]==0){
                    ptr[i].gene[j]=1;
                }
                
            }
        }
    }
    
}
void crossover(struct population *ptr,int p_size,int g_size){
    
    int i,j;
    int cut;
    int tmp=0;
    for (i=0; i!=p_size; i=i+2) {
        cut=rand()%(g_size-1);
        if (rand()%100<=c_rate) {
            for (j=cut; j!=g_size; j++) {
                tmp=ptr[i].gene[j];
                ptr[i].gene[j]=ptr[i+1].gene[j];
                ptr[i+1].gene[j]=tmp;
            }
        }
    }
    mutation(ptr,p_size,g_size);
    for (i=0; i!=p_size; i++) {
        
        ptr[i].fitness=0;
        
    }
    for (i=0; i!=p_size; i++) {
        
        ptr[i].fitness=btod(ptr[i].gene,g_size);
        ptr[i].fitness=func(ptr[i].fitness);
        
    }
    
}

void generation(struct population *ptr,struct population *newptr,int p_size,int g_size){
    
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
        wheel1=rand()*100%sum_fit;
        wheel2=rand()*100%sum_fit;
        for (j=0; j!=p_size; j++) {
            if(wheel1>ptr[j].fitness){
                wheel1=wheel1-ptr[j].fitness;
            }
            else{
                w1=ptr[j];
            }
            if(wheel2>ptr[j].fitness){
                wheel2=wheel2-ptr[j].fitness;
            }
            else{
                w2=ptr[j];
            }
        }
        
        newptr[i]=w1;
        newptr[i+1]=w2;
        
    }
    ptr=newptr;
    crossover(ptr,p_size,g_size);
    showpopulation(ptr,p_size,g_size);
    
    
    
    
}





int main(){
    
    int p_size;
    int g_size;
    struct population *ptr,*newptr;
    int i,j;
    srand(time(NULL));
    
    printf("input population size\n");
    scanf("%d",&p_size);
    printf("input gene size\n");
    scanf("%d",&g_size);
    
    ptr=malloc(p_size*sizeof(struct population));
    newptr=malloc(p_size*sizeof(struct population));
    
    for (i=0; i!=p_size; i++) {
        
        ptr[i].gene=malloc(g_size*sizeof(int));
        
        for (j=0; j!=g_size; j++) {
            
            ptr[i].gene[j]=rand()%2;
            
        }
        
        ptr[i].fitness=btod(ptr[i].gene,g_size);
        ptr[i].fitness=func(ptr[i].fitness);
        
    }
    
    
    showpopulation(ptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    generation(ptr,newptr,p_size,g_size);
    
    
    
    
    
    
   
    
    
}

