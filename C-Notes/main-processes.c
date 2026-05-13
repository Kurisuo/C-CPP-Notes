#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char* argv[]){ 
    int x = 2;
    int pid = fork(); //fork makes a new process
    
    if (pid == -1){
        return 1;
    }
    
    if (pid == 0){ //returned to child process
        x++;
    }

    sleep(2);
    printf("value of x: %d\n", x);
 
    printf("Process id %d\n", getpid());
    
    if (pid != 0){ 
        wait(NULL);
    }
    return 0;
}