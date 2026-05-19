#include <stdio.h>
#include <pthread.h>


#define R 100000
long counter = 0;

void* thread_func(void *arg){ 

    for(int i = 0; i < R; i++){
        counter++;
    }
    return NULL;
}

int main(void){ 
    pthread_t thread1;

    pthread_create(&thread1, NULL, &thread_func, NULL);
    pthread_join(thread1, NULL);
    printf("Counter is at: %ld. \n\nExpected: %d", counter, 2 * R);
    return 0;
}