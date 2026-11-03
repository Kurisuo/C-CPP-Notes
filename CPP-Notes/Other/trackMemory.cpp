#include <iostream>

struct AllocationMetric { 

    uint32_t totalAllocated = 0;
    uint32_t totalFreed = 0;

    uint32_t CurrentUsage() {return totalAllocated - totalFreed;}

};

static AllocationMetric s_AllocationMetric;


void* operator new(size_t size){

    s_AllocationMetric.totalAllocated = size;
    return malloc(size); 
} //do not use standard new operator, use ours instead


void operator delete(void* memory, size_t size){ 
    s_AllocationMetric.totalFreed += size;
    free(memory);
}

struct Object { 

    int x, y, z;

};

static void printMemUsage(){ 

    std::cout << "Mem Usage: " << s_AllocationMetric.CurrentUsage() << " bytes\n";
}


int main(){ 

    printMemUsage();
    std::string str = "Meow";
    printMemUsage();
    {
    std::unique_ptr<Object> obj = std::make_unique<Object>();
    }

    Object* obj = new Object; //allocated on the heap
}