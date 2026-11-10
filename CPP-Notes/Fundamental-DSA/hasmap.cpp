#include <unordered_map>
#include <vector>
#include <stdio.h>

//Walk the input form left to right 
//For each item, ask the MAP, have i already encountered this item?
//write down the item for the items after it 


int hashMaptemp(const vector<int>& a, int target){ 
    std::unordered_map<int, int> seen;
    for(int i = 0; i < (int)a.size(); ++i){ 
        int want = target - a[i];
        auto it = seen.find(want);
        if(it != seen.end()) return it.second;
        seen.emplace(a[i], i);

    }

    return -1;
}