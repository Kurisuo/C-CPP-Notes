//Pseudocode for parallel search


int[] data {4, 6, 7, 1, 2, 5, 8};
int numElements = ciel(data.length / numThreads);
Thread[] threads = new Threads[numThreads];
for(int i = 0; i < numThreads; i++){

    int startIdx = i * numElements;
    int endIdx = startIdx + numElements;
    int[] data = slice(data, startIdx, endIdx);
    int x = threads[i].start(pSearch(data, x));
}

int pSearch(data, x){ 
    for(int index = 0; index < data.length; index++){ 
        if(data[index] == x){
            killThreads();
            return index;
        }

    }

}