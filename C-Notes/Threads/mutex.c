#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Spawns 3 threads
Each thread receives its ID (0, 1, 2) via the void* kludge
Each thread does ++counter 100,000 times, protected by a mutex
Main joins all threads and prints the final counter (should be 300,000)
Each thread also prints "Thread X done" after its loop

*/

#define THREADS 3
#define ITER 1000000

long counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void* arg) { 

    int id = (int)(intptr_t)arg;

    for (int i = 0; i < ITER; i++) { 
        pthread_mutex_lock(&mutex);
        ++counter;
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread %d complete\n", id);
    return NULL;
}

int main(void) { 

    pthread_t t[THREADS];

    for (int i = 0; i < THREADS; i++) { 
        pthread_create(&t[i], NULL, thread_func, (void* )(intptr_t) i);
    }
    for (int i = 0; i < THREADS; i++) { 
        pthread_join(t[i], NULL);
    }

    printf("Final counter: %ld\n", counter);

    return 0;
}






