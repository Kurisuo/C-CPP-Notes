#include <atomic>
#include <cstddef>


/*

ALock - a queue lock that uses an array of boolean flags.
-> An atomic counter assignes each thread a slot
-> When a threads boolean turns true, it its turn, when it concludes, it turns the next flag to true



*/

//setting up flags

constexpr std::size_t N = 8;

std::atomic<std::size_t> tail{0};
std::atomic<bool> arr[N]{};

void initialize(){

    arr[0].store(true);
}


//aquiring lock 

std::size_t lock(){ 

    std::size_t slot = tail.fetch_add(1) % N;
    while(!arr[slot].load()){ }

    return slot;
}


//releasing lock 

void unlock(std::size_t slot){ 
    //access shared data
    unlock(my_slot);

}