#include <pthread.h>
#include <stdio.h>
#include <stdatomic.h>
#include <stdbool.h>


#define N 4 //Thread Num

//Volatile forces compiler to re-read from memory every time
volatile int number[N] = {0}; //Set num to 0 for all Threads
volatile bool entering[N] = {false}; //Sets Entering Flag to False for all Threads


//inline is ilke a copy-paste, ensures immediate execution onto the calle's program
//static is a fall back here in cause the function is too big, sets the function privately to its corresponding source file
static inline int lamport(int na, int a, int nb, int b){ 
    return (na < nb) || (na == nb && a < b);
}

void bakery_lock(int i){ 
    //Enter to choose number
    entering[i] = true; //set thread I's flag to true
    int m = 0; //max
    for(int j = 0; j < N; j++){ 
        int nj = number[j]; // read each current number of the threads
        if (nj > m) m = nj;
    } 
    number[i] = m + 1; //set number for thread
    entering[i] = false; // lower flag of thread i

    //Bakery: Wait until we have lowest ticket 
    for(int j = 0; j < N; j++){ 
        if(j == i) continue;
        while(entering[j]){/*spin*/} //wait for thread j to pick number
        while(number[j] != 0 && lamport(number[j], j, number[i], i)){/*spin*/}
    }
    //crit region
}

void bakery_unlock(int i){ 
    number[i] = 0;
}

//Busy-wait is unavoidable when using pure software techniques