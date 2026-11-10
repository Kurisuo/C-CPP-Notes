// fastslow.cpp  —  g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined fastslow.cpp -o fastslow && ./fastslow
#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Return the middle node. For an even length, return the SECOND middle.
//   1 2 3 4 5 -> 3      1 2 3 4 -> 3      empty -> nullptr
Node* middle(Node* head) {
    // TODO 1: slow moves 1, fast moves 2. When fast can't move 2 anymore, slow is the middle.
    return nullptr;
}

// Return true if following next pointers ever loops back.
bool has_cycle(Node* head) {
    // TODO 2: same two pointers. If they ever land on the same node -> cycle.
    //         If fast falls off the end (nullptr) -> no cycle.
    (void)head;
    return false;
}

// Return the n-th node from the end (n = 1 means the last node). Assume 1 <= n <= length.
//   1 2 3 4 5, n = 2 -> 4
Node* nth_from_end(Node* head, int n) {
    // TODO 3: not fast/slow speed, but a GAP: move `lead` n steps first, then move both until lead is nullptr.
    (void)head; (void)n;
    return nullptr;
}

// ---------------- tests (don't change) ----------------
std::vector<Node*> build(const std::vector<int>& vals) {
    std::vector<Node*> nodes;
    for (int v : vals) nodes.push_back(new Node(v));
    for (size_t i = 0; i + 1 < nodes.size(); i++) nodes[i]->next = nodes[i + 1];
    return nodes;
}
void freeAll(std::vector<Node*>& nodes) { for (Node* n : nodes) delete n; }
int passed = 0, failed = 0;
void check(bool ok, const char* name) { if (ok) passed++; else { failed++; std::cout << "FAIL " << name << "\n"; } }
int main() {
    { auto n = build({1,2,3,4,5}); check(middle(n[0]) == n[2], "middle of odd length"); freeAll(n); }
    { auto n = build({1,2,3,4});   check(middle(n[0]) == n[2], "middle of even length = second middle"); freeAll(n); }
    { auto n = build({1});         check(middle(n[0]) == n[0], "middle of one node"); freeAll(n); }
    { check(middle(nullptr) == nullptr, "middle of empty"); }
    { auto n = build({1,2,3,4});   check(!has_cycle(n[0]), "no cycle"); freeAll(n); }
    { auto n = build({1,2,3,4});   n[3]->next = n[1]; check(has_cycle(n[0]), "cycle back to node 2");
      n[3]->next = nullptr; freeAll(n); }
    { auto n = build({1});         n[0]->next = n[0]; check(has_cycle(n[0]), "single node pointing to itself");
      n[0]->next = nullptr; freeAll(n); }
    { check(!has_cycle(nullptr), "empty has no cycle"); }
    { auto n = build({1,2,3,4,5}); check(nth_from_end(n[0], 2) == n[3], "2nd from end"); freeAll(n); }
    { auto n = build({1,2,3,4,5}); check(nth_from_end(n[0], 5) == n[0], "5th from end = head"); freeAll(n); }
    { auto n = build({1,2,3,4,5}); check(nth_from_end(n[0], 1) == n[4], "1st from end = last"); freeAll(n); }
    std::cout << passed << " passed, " << failed << " failed\n";
    return failed ? 1 : 0;
}