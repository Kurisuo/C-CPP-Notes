#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void* roll_dice(){ 
    int value = (rand() % 6) + 1;
    printf("%d\n", value);
    return NULL;
}




int main(int argc, char* argv[]){ 
    srand(time(NULL)); //!NEW!
    pthread_t thread_1;
    

    return 0;
}