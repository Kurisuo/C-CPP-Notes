#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, int> counts;

//Insert 
counts[7] = 1; // Key : 7 Val : 1
counts[7]++; //increment val at key

bool exists = counts.find(7) != counts.end();
counts.erase(7); //Remove Entry


std::unordered_set<int> seen;

seen.insert(7);
bool visited = seen.find(7) != seen.end();

//Fixed Sized-Keys, Lookup, Insertion, and Removal take O(1) - O(N) worst case
//storing n-elements uses O(n) space

/*

Use a map when we need to find items by identity.
--> Scanning an unsorted array costs O(n) per lookup
about:blank#blocked
--> Arrays are better at sequential numerical work - such as scanning weights

*/


std::vector<int> req {7, 4, 7, 7};
std::unordered_map<int, int> counts;

for (int id : req){ 
    counts[id]++:
}

7   7 -> 1
4   7 -> 1, 4 -> 1
7   7 -> 2, 4 -> 1
7   7 -> 3, 4 -> 1

// Time: O(n) Space: O(u) - where u is the distinct num of IDs

