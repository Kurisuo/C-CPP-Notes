#include <atomic> 



//CLH Lock - Threads spin on its predecessor's flag

struct CLHNode { 
    std::atomic<bool> locked{false};
};

CLHNode dummy;
std::atomic<CLHNode*> tail(&dummy);


//my curr node 
mine -> locked.store(true);
pred = tail.exchange(mine); //places node at the back - return node previosly at the back
while(pred -> locked.load()){ 
}

//releasing lock

mine -> locked.store(false);
mine = pred;
