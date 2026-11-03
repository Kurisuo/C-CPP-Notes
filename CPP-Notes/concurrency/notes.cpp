#include <atomic>

std::atomic<int> a; 
std::atomic<Node *> pntr;
fetch_add(1); //increments and returns old value
exchange(value); //replace and returb old value
std::atomic_compare_exchange_strong(); //Replace only if current value matches

std::atomic<int> counter{0};
int ticket = counter.fetch_add(1);

//CAS compare and swap

int expected = 1;

bool changed = counter.compare_exchange_strong(expected, 2);
//if counter is still 1, change it to 2 

