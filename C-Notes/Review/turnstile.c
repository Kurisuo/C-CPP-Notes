#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int threads_arrived = 0;
int total_threads = 4;

sem_t mutex;     // Protects the 'threads_arrived' counter
sem_t turnstile; // The actual gate holding the threads back

void* custom_barrier_example(void* arg) {
    // --- ARRIVAL PHASE ---
    sem_wait(&mutex);      // Lock the counter
    threads_arrived++;     // Announce arrival
    
    if (threads_arrived == total_threads) {
        // I am the final thread! Unlock the turnstile!
        sem_post(&turnstile); 
    }
    sem_post(&mutex);      // Unlock the counter

    // --- THE TURNSTILE ---
    sem_wait(&turnstile);  // Wait for the gate to unlock
    sem_post(&turnstile);  // I got through! Unlock it for the next guy!

    // Critical group work happens here!
    
    return NULL;
}