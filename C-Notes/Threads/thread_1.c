#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
/*

From main, creates one thread.
The thread prints "Hello from the thread" and returns NULL.
main joins the thread, then prints "Goodbye from main".

*/

void *thread_func(void *arg){ 
    printf("Hello from the thread\n");
    return NULL;
}


int main(void){ 
    pthread_t thread_1;
   // uintptr_t rv_1;

    int code = pthread_create(&thread_1, NULL, thread_func, NULL);
    if (code != 0) {fprintf(stderr, "Error in Thread Create\n"); exit(1);}
  //  pthread_join(thread_1, NULL);
    printf("Goodbye from main\n");
    return 0;
}



