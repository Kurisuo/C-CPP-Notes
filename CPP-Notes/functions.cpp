#include <iostream>
#include <string>

struct Elem {
    int data;
    Elem* next;
};

Elem* next_elem(){ //return pointer to Elem
    return nullptr;
}

double get(const vector<double>& vec, int index){ 
    return 0.0;
}

char& String::operator[](int index){ 
    return data[index];
} //A function member to a class bears its signature


//If two functions bear a similar name, the compiler will try to find the best match for the function call. This process is called overload resolution. The compiler will consider the number and types of the arguments passed to the function, as well as the return type of the function, to determine which function to call. If there are multiple functions that could be called, the compiler will choose the one that is the best match for the arguments provided. If there is no clear best match, or if there are multiple equally good matches, the compiler will generate an error.

void print(int);
void print(double);
void print(string);

void user() {
    print(42); // calls print(int)
    print(3.14); // calls print(double)
    print("Hello"); // calls print(string)
}

int main() { 

    return 0;
}