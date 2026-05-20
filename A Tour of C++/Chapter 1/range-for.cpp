#include <iostream>

using namespace std;

void print(){ 

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for(auto x : v) //for each x in v
        cout << x << '\n';
    for(auto x : {1, 2, 3, 4, 5})
        cout << x << '\n';
}

void increment(){ 

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (auto& x : v) //unary suffix & implies reference to
        ++x;

}

//References are useful for specifying function arguments
void sort(vector<double>&);