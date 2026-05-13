#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int mails = 0;
pthread_mutex_t mutex;



void* routine(){ 
    for(int i = 0; i < 1000000 ; i++) {
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
    pthread_t thread_1, thread_2;
    pthread_mutex_init(&mutex, NULL); //initilaize mutex


    if (pthread_create(&thread_1, NULL, &routine, NULL) != 0){
        return 1;
    }
    if (pthread_create(&thread_2, NULL, &routine, NULL) != 0){
        return 2;
    }
    if (pthread_join(thread_1, NULL) != 0){ 
        return 3;
    }
    if (pthread_join(thread_2, NULL) != 0){ 
        return 4;
    }

    pthread_mutex_destroy(&mutex); //destroy mutex
    
   printf("Number of mails: %d\n", mails);

    return 0;
}