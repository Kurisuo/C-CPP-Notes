#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

//globals

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

// mutex

pthread_mutex_lock(&mutex);
pthread_mutex_unlock(&mutex);

//cond var
pthread_cond_wait(&condvar, &mutex);
pthread_cond_signal(&condvar);
pthread_cond_broadcast(&condvar);

void *threadfunc(void *arg){}


pthread_create(&thread, NULL, func, arg);
pthread_join(thread, NULL);


