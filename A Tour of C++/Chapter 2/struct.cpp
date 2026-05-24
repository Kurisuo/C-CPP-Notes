#include <iostream>

using namespace std;

struct Vector { 
    double* elem;
    int numElements;
};

void vector_init(Vector& v, int s){ 
    v.elem = new double[s]; //allocate array of s elements
    v.numElements = s;
}

double read_Sum(int s){ 

    Vector v;
    vector_init(v, s); //initialize struct
    
    for (int i = 0; i != s; ++i){ 
        cin >> v.elem[i];
    }

    double sum = 0;
    for (int i = 0; i != s; ++i){ 
        sum += v.elem[i];
    }
    return sum;
}


void ex(Vector v, Vector& rv, Vector* pv){ 
    int ex1 = v.numElements; //access through name 
    int ex2 = rv.numElements; //access through reference 
    int ex3 = pv -> numElements; //access through a pointer

}