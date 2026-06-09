



void globals { 
    Cv cv;
    Lock lock;
    int num_frying_pans = N;
}


void cook() { 


    //get frying pan safely
    aquire(lock;)
    while(num_frying_pans == 0){ 
        wait(cv, lock);
    }
    
    FryingPan frying_pan = get_frying_pan() //when available!
    num_frying_pans += 1; //increase frying pans used;
    release(lock);

    cook_with(frying_pan);
    aquire(lock);
    return_frying_pan(frying_pan);
    num_frying_pans -= 1;
    signal(cv);
    release(lock);

}