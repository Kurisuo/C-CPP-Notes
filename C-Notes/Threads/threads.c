#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void* routine(){ 
    printf("test from threads\n");
    sleep(3);
    printf("Ending thread");
}


int main(int argc, char* argv[]) { 
    pthread_t thread_1, thread_2;
    if (pthread_create(&thread_1, NULL, &routine, NULL) != 0){
        return 1;
    }
    if (pthread_create(&thread_2, NULL, &routine, NULL) != 0){
        return 1;
    }
    if (pthread_join(thread_1, NULL)){ 


    }
    pthread_join(thread_2, NULL);
    if (pthread_join(thread_1, NULL)){ 


    }

    return 0;
}