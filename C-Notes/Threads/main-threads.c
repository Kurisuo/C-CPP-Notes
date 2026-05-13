#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void* routine(){ 
    x++;
    sleep(2);
    printf("value of x: %d\n", x);
}

void* routine_2(){ 
    sleep(2);
    printf("process id %d\n", getpid());
}

int main(int argc, char* argv[]){ 
    pthread_t thread_1;
    pthread_t thread_2;

    pthread_create(&thread_1, NULL, &routine, NULL);
    pthread_create(&thread_2, NULL, &routine_2, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    return 0;
}

//threads can access the same variables, live within the same memory space
//processes provide seperate memory spaces
//security context is shared, share memory -> issues with modyfing the same variable