#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int mails = 0;
int lock = 0;


void* routine(){ 
    for(int i = 0; i < 1000000 ; i++) {
        if (lock == 1) {
            // wait until the lock is 0
        }

        lock = 1;
        mails++;
        lock = 0;
        // read mails
        // increment 
        // write mails
    }
}

int main(int argc, char* argv[]) { 
    pthread_t thread_1, thread_2;
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
    
   printf("Number of mails: %d\n", mails);

    return 0;
}