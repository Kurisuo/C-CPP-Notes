#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void* thread_func(){ 
    printf("Thread 1 running\n");
}


int main(int argc, char* argv[]){ 
    pthread_t thread_1;
    pthread_t thread_2;

    if(pthread_create(&thread_1, NULL, &thread_func, NULL) != 0){
        return -1;
    }

    if (pthread_join(thread_1, NULL) != 0){ 
        return -1;
    }

    return 0;
}