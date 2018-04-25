#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    srand(time(NULL));

    struct population *new;
    int i,j;

    new=malloc(p_size*sizeof(struct population));
    for (i=0; i!=p_size; i++){
        for (j=0; j!=g_size; j++){
            new[i].gene[j]=1;
        }
    }

    mutation(new);
    for(i=0; i!=p_size; i++){
        for(j=0; j!=g_size; j++){
            printf("%d ",new[i].gene[j]);
        }
        
    }
   
    
    
    return 0;
}
