#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_FOR_RAND 10
#define MAX_FOR_RAND 100

int main(){
    srand(time(NULL));
    for(int k = 0; k<200;k++){
        int i = MIN_FOR_RAND +rand()%(MAX_FOR_RAND-MIN_FOR_RAND+1);
        printf("k: %d, random: %d\n",k,i);
    }
    
    return 0;
}