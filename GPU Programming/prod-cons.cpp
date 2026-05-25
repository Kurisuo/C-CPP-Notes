#include <iostream>
#include <thread>
#include <deque> 
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <random>

//Allows us to create a sequence container which grants us fast insertion and deletion at both ends 
using std::deque; //Double Ended Queue | O(1) Time | Utilizes Fixed-size memory blocks managed by a central map

std::mutex mu, cout_mu; //mutex to protect shared buffer and cout mutex to protect printf
std::condition_variable cond; //conditional var


//Mersenne Twister 19937 algorithm 
//naming it generate
//calling the constructor by using parenthesis
//std::chrono::steady_clock -> asking for current time to get unique seed for generator
//::now() used for grabbing EXACT time on the clock
//.time_since_epoch() --> time elapsed since computer initally booted up
//.count() gives us an exact number of hardware ticks that have elapsed

std::mt19937 generate(std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> dist(0, 99);








class Buffer { 

    public:
        void add(int num){ 


        }

    private:
        deque<int> buffer_;
        const unsigned int size_ = 10;
};

class Producer { 



}


class Consumer {}

int main(){ 


    Buffer b;
    Producer p1(&b, "prod1");
    Producer p2(&b, "prod2");

    Consumer c1(&b, "cons1");
    Consumer c2(&b, "cons2");

    std::thread producer_thread1(&Producer::run, &p1);
    std::thread producer_thread2();

    std::thread consumer_thread1();
    std::thread consumer_thread2();

}