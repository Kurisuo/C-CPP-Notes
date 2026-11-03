#include <atomic>
#include <thread>


//Queue Locks: Waiting in Line rather than Competing repeatedly

/*
A queue lock arranges waiting threads into an order
Each of those threads await a signal associated with its place in the queue

Two Problems Addressed:
- Cache Coherence Traffic: Numerous processors attempt to access the same shared lock variable
- Underutilization: the lock becomes free while the waiting threads are still delaying before retrying 


This type of lock provides FIFO fairness in the order threads join the queue

*/






