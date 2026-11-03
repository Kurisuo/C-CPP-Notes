#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){ 

    string txt = "hello";
    unordered_map<char, int> freqMap;
    
    for(char c : txt) { 
        freqMap[c]++;
    }
    for(auto const& [character, count] : freqMap) { 
        cout << "'" << character << "': " << count << endl; 
    }
    return 0;
}