#include <pthread.h>
#include <stdio.h>

volatile int turn = 0;

void critical_region(int id){ 
    printf("Thread %d in critical region\n", id);
}

void noncritical_region(int id){ 
    //
}

void* thread_0(void* arg){ 
    while(1){ 
        while(turn != 0){/*spin*/}
        critical_region(0);
        turn = 1;
        noncritical_region(0);
    }
    return NULL;
}

void* thread_1(void* arg){ 
    while(1){ 

        while(turn != 1){ /*Spin*/}
            critical_region(1);
            turn = 0;
            noncritical_region(1);
        }
    return NULL;
}