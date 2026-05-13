#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* func(){ 


    return NULL;
}



int main(int argc, char* argv[]){ 
    pthread_t thread;
    if (pthread_create(&thread, NULL, &func, NULL) != 0){ 
        perror;
    }

}