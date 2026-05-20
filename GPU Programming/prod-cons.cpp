#include <iostream>
#include <thread>
#include <deque> 
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <random>

//Allows us to create a sequence container which grants us fast insertion and deletion at both ends 
using std::deque; //Double Ended Queue | O(1) Time | Utilizes Fixed-size memory blocks managed by a central map

std::mutex mu, cout_mu;
std::condition_variable cond; 


class Buffer { 

    public:
        void add(int num){ 


        }

    private:
        deque<int> buffer_;
        const unsigned int size_ = 10;
};