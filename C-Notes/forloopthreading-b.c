#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int mails = 0;
pthread_mutex_t mutex;



void* routine(){ 
    for(int i = 0; i < 99000000 ; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);

        // read mails
        // increment 
        // write mails
    }
    return NULL;
}

int main(int argc, char* argv[]) { 
    pthread_t threads[4];
    int i;
    pthread_mutex_init(&mutex, NULL); //initilaize mutex
    
    for (i = 0; i < 4; i++ ){ 
        if (pthread_create(threads + i, NULL, &routine, NULL) != 0){
            return 1;       
        }
        printf("Thread %d has started", i);
    }
//Seperate for-loops to allow parallelism 
//Join threads in a seperate for-loop, otherwise we do not truly have a multi-threaded program
   
    for (i = 0 ; i < 4; i++){
        if (pthread_join(threads[i], NULL) != 0){
            return 2;
        }    
        printf("Thread %d has finished execution\n", i);
    }

    pthread_mutex_destroy(&mutex); //destroy mutex   
    printf("Number of mails: %d\n", mails);

    return 0;
}