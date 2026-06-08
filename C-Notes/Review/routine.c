#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//#define THREADS 12;


sem_t semaphore;

void charge_credit_card(int args){
    printf("Charged Credit Card belonging to Customer: %d!\n\n", args);
}

void* process_payment(void* args){ 

    int shopper_id = *(int*)args;

    sem_wait(&semaphore);
    printf("Customer %d got inside!\n\n", shopper_id);
    
    charge_credit_card(shopper_id);
    sleep(2);
    
    sem_post(&semaphore);

    return NULL;
}

int main(int argc, char* argv[]){ 

    sem_init(&semaphore, 0, 4); //only allow 4 at a time to access crit section
    pthread_t shopper_threads[12]; //threads
    int shoppers_in[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //persons inside

    int i;
    for(i = 0; i < 12; i++){ 
        pthread_create(&shopper_threads[i], NULL, &process_payment, &shoppers_in[i]);
    }

    for(i = 0; i < 12; i++){
        pthread_join(shopper_threads[i], NULL);
    }

    sem_destroy(&semaphore);


    return 0;
}