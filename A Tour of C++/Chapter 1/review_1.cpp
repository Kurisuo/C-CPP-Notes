#include <iostream>
using namespace std;

consteval char generateKey(int x){
    return {-x};
}

int main(){ 

    char arr[] {"Brace Initialization"};
    const auto key {generateKey(5)};

    for(auto& x : arr){
        if (x == '\0') break;
        
        auto res = x ^ key;
        auto comp = ~(res);
        x = comp;
    
        cout << +x << " ";
    }

    return 0;
}