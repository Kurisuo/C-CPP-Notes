#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


#define THREADS 4;

sem_t semaphore; //create semaphore object

void* routine(void* args){ 

    printf("Hello from thread %d\n", *(int*)args);
    free(args);
}


int main(int argc, char *argv[]){
    pthread_t thread[THREADS];

    sem_init(&semaphore, 0, 1); //third parameter is starting val of sempahore; initliaze



    int i;
    for(i = 0; i < THREADS; i++){ 
        int* a = malloc(sizeof(int));
        *a = i;
        if(pthread_create(&thread[i], NULL, &routine, a) != 0) perror("err");
    }

    for(i = 0; i < THREADS; i++){
        if(pthread_join(&thread[i], NULL) != 0){ 
            perror("err");
        }
    }
    sem_destroy(&semaphore); //destroy address to the semaphore


    return 0;
}

