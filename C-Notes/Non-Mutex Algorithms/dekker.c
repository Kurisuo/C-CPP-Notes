#include <pthread.h>
#include <stdbool.h>

volatile bool wants_to_enter[2] = {false, false};
volatile int  turn = 0;

void lock(int self) {
    int other = 1 - self;
    wants_to_enter[self] = true;            // I'm interested

    while (wants_to_enter[other]) {         // is the other guy also interested?
        if (turn != self) {                 // if it's not my turn, back off
            wants_to_enter[self] = false;   // politely lower my flag
            while (turn != self) {          // wait for my turn
                /* busy wait */
            }
            wants_to_enter[self] = true;    // raise my flag again, try again
        }
        // if turn == self, just keep checking the outer condition
        // (the other thread will eventually lower its flag)
    }
    // I'm in!
}

void unlock(int self) {
    turn = 1 - self;                        // hand the turn to the other
    wants_to_enter[self] = false;           // I'm done, drop my flag
}

void *thread_fn(void *arg) {
    int id = *(int *)arg;
    while (1) {
        lock(id);
        // critical section
        unlock(id);
        // noncritical section 
    }
    return NULL;
}