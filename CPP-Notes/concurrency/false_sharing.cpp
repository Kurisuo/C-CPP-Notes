//False Sharing 

/*

False Sharing occurs when 
different variables occupy the same cache-line,
so writing to one causes cache invalidations in the other

Cache Line: Block of memory that a processor caches and tracks together

-> in Alock, two threads may change two different flags that occupy the same cache-line
*/


//We can pad them this way:

//uses a 64-byte boundary between objects
struct alignas(64) Slot { 

    std::atomic<bool> ready{false};

};

Slot slots[8];

//diff vars do not always imply diff cache-lines!