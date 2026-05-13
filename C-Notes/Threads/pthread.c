#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


void* roll_dice(){ 
    int value = (rand() % 6) + 1;
    int* result = malloc(sizeof(int));
    *result = value;
    return (void*) result;
}

int main(int argc, char* argv[]){ 
    int* res;
    srand(time(NULL)); //!NEW!
    pthread_t thread_1;
    if(pthread_create(&thread_1, NULL, &roll_dice, NULL) != 0){ 
        return 1;
    }

    if(pthread_join(thread_1, (void**) &res) != 0){
        return 2;
    }

    printf("Main res: %p\n", res);
    printf("Results: %d\n", res);
    
    free(res);
    return 0;
}