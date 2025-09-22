#include <rbtree.h>
#include <bstree.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define MIN_FOR_RAND 10000
#define MAX_FOR_RAND 1000000
#define BIGGEST_N 200001
#define SMALLEST_N 1
#define ITERATION_CYCLES 1


double wtime()
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main(){
    double all_time = wtime();
    RBtree *RB_average = rbtree_create();
    RBtree *RB_worst = rbtree_create();

    BStree *BS_average = bstree_create();
    BStree *BS_worst = bstree_create();

    
    
    srand(time(NULL));
    
    
    
    for(int i = SMALLEST_N; i<BIGGEST_N;i++){
        
        bstree_add(BS_worst,i,'k');
        rbtree_add(RB_worst,i,'k');
        int random_numb = MIN_FOR_RAND +rand()%(MAX_FOR_RAND-MIN_FOR_RAND+1);
        bstree_add(BS_average,random_numb,'k');
        rbtree_add(RB_average,random_numb,'k');
        

        if(i%20000==0){
            double bstlkp_a=0, rblkp_a=0, bstlkp_w=0, rblkp_w=0, bstmx_a=0, rbmx_a=0, rbmx_w=0;// bstmx_w=0,
            double t = wtime();

            for(int k =0; k<ITERATION_CYCLES;k++){
                int rand_search = SMALLEST_N + rand()%(BIGGEST_N-SMALLEST_N+1);
                t = wtime();
                bstree_lookup(BS_worst->root,rand_search);
                bstlkp_w = wtime() -t;
            }
            bstlkp_w /= ITERATION_CYCLES;

            for(int k =0; k<ITERATION_CYCLES;k++){
                int rand_search = MIN_FOR_RAND +rand()%(MAX_FOR_RAND-MIN_FOR_RAND+1);
                t = wtime();
                bstree_lookup(BS_average->root,rand_search);
                bstlkp_a += wtime() -t;
            }
            bstlkp_a /= ITERATION_CYCLES;
            

            for(int k =0; k<ITERATION_CYCLES;k++){
                int rand_search = MIN_FOR_RAND +rand()%(MAX_FOR_RAND-MIN_FOR_RAND+1);
                t = wtime();
                rbtree_lookup(RB_average->root,RB_average->nil,rand_search);
                rblkp_a += wtime() -t;
            }
            rblkp_a /= ITERATION_CYCLES;

            for(int k =0; k<ITERATION_CYCLES;k++){
                int rand_search = SMALLEST_N + rand()%(BIGGEST_N-SMALLEST_N+1);
                t = wtime();
                rbtree_lookup(RB_worst->root,RB_worst->nil,rand_search);
                rblkp_w += wtime() -t; 
            }
            rblkp_w /= ITERATION_CYCLES;

            for(int k =0; k<ITERATION_CYCLES;k++){
                t = wtime();
                bstree_max(BS_average->root);
                bstmx_a += wtime() -t;
            }
            bstmx_a /= ITERATION_CYCLES;

            for(int k =0; k<ITERATION_CYCLES;k++){
                t = wtime();
                rbtree_max(RB_average->root,RB_average->nil);
                rbmx_a += wtime() -t;
            }
            rbmx_a /= ITERATION_CYCLES;

            //for(int k =0; k<ITERATION_CYCLES;k++){
            //    t = wtime();
            //    bstree_max(BS_worst->root);
            //    bstmx_w += wtime() -t;
            //}
            //bstmx_w /= ITERATION_CYCLES;

            for(int k =0; k<ITERATION_CYCLES;k++){
                t = wtime();
                rbtree_max(RB_worst->root,RB_worst->nil);
                rbmx_w += wtime() -t;
            }
            rbmx_w /= ITERATION_CYCLES;
        
            printf("%d\t%.09f\t%.09f\t%.09f\t%.09f\t%.09f\t%.09f\t%.09f\t\n",
            i,bstlkp_a,rblkp_a,bstlkp_w,rblkp_w,bstmx_a,rbmx_a,rbmx_w); //,bstmx_w

            
        
        }
        

    }
    printf("Height: %d\n",rbtree_height(RB_worst->root,RB_worst->nil));
    //rbtree_print_dfs(RB_average->root,RB_average->nil,0);
    //printf("root color: %d\n",RB_average->root->color);

    rbtree_free(RB_average);
    rbtree_free(RB_worst);
    bstree_free(BS_average);
    bstree_free(BS_worst);

    

    printf("all time is: %.03f\n",wtime()-all_time);
    
 
    
    
    

    return 0;
}


