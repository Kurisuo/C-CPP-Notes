// doubly.cpp  —  g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined doubly.cpp -o doubly && ./doubly
#include <iostream>
#include <vector>

struct DNode {
    int key;
    DNode* prev;
    DNode* next;
    DNode(int k) : key(k), prev(nullptr), next(nullptr) {}
};

// Sentinels: head_ and tail_ are fake nodes that are ALWAYS there.
// Real nodes live between them:  head_ <-> a <-> b <-> tail_
// So every real node always has a prev and a next: no null checks needed.
class DoublyList {
public:
    DoublyList() : head_(new DNode(-1)), tail_(new DNode(-1)) {
        head_ -> next = tail_;
        tail_ -> prev = head_;
    }
    ~DoublyList() {
        DNode* cur = head_;
        while (cur) { DNode* nxt = cur->next; delete cur; cur = nxt; }
    }

    // Insert a new node right after head_. Return it (callers keep this pointer).  O(1)
    DNode* push_front(int k) {
        DNode* newNode = new DNode(k);
        DNode* old_first_node = head_ -> next;
        // TODO 1: wire up 4 pointers: n->prev, n->next, and the two neighbors
       
        head_ -> next = newNode;
        newNode -> prev = head_;
        newNode -> next = old_first_node;
        old_first_node -> prev = newNode;

       
        return newNode;
    }

    // Unlink node n from the list (do NOT delete it).  O(1)
    void unlink(DNode* n) {
        // TODO 2: make n's neighbors point at each other

       n -> prev -> next = n -> next;
       n -> next -> prev = n -> prev; 
    }

    // Move an existing node to the front.  O(1)  (this is exactly what LRU Cache does on a hit)
    void move_to_front(DNode* n) {
        // TODO 3: reuse unlink, then put n right after head_ (don't allocate)
       
        unlink(n);        

        DNode* old_first = head_ -> next;
        head_ -> next = n;
        n -> prev = head_;
        n -> next = old_first;
        old_first -> prev = n;


    }

    // Remove the last real node and return its key; return -1 if empty.  O(1)
    int pop_back() {
        // TODO 4: the last real node is tail_->prev. Empty means tail_->prev == head_.


        if (tail_ -> prev == head_){return -1;}

        
        DNode* to_delete = tail_ -> prev;
        int key = to_delete -> key;
        
        unlink(to_delete);
        delete to_delete;

        return key;
    }

    std::vector<int> forward() const {
        std::vector<int> out;
        for (DNode* c = head_->next; c != tail_; c = c->next) out.push_back(c->key);
        return out;
    }
    std::vector<int> backward() const {
        std::vector<int> out;
        for (DNode* c = tail_->prev; c != head_; c = c->prev) out.push_back(c->key);
        return out;
    }

private:
    DNode* head_;
    DNode* tail_;
};

// ---------------- tests (don't change) ----------------
int passed = 0, failed = 0;
void show(const std::vector<int>& v) { std::cout << "["; for (size_t i = 0; i < v.size(); i++) std::cout << (i ? "," : "") << v[i]; std::cout << "]"; }
void check(const DoublyList& l, const std::vector<int>& want, const char* name) {
    std::vector<int> back(want.rbegin(), want.rend());
    if (l.forward() == want && l.backward() == back) { passed++; return; }
    failed++;
    std::cout << "FAIL " << name << ": forward "; show(l.forward()); std::cout << " backward "; show(l.backward());
    std::cout << " want forward "; show(want); std::cout << "\n";
}
void checkInt(int got, int want, const char* name) {
    if (got == want) { passed++; return; }
    failed++; std::cout << "FAIL " << name << ": got " << got << " want " << want << "\n";
}
int main() {
    { DoublyList l; check(l, {}, "empty"); checkInt(l.pop_back(), -1, "pop_back on empty"); }
    { DoublyList l; l.push_front(1); l.push_front(2); l.push_front(3); check(l, {3,2,1}, "push_front x3 (both directions)"); }
    { DoublyList l; l.push_front(1); DNode* b = l.push_front(2); l.push_front(3);
      l.unlink(b); delete b; check(l, {3,1}, "unlink middle"); }
    { DoublyList l; DNode* a = l.push_front(1); l.push_front(2);
      l.unlink(a); delete a; check(l, {2}, "unlink last real node"); }
    { DoublyList l; DNode* a = l.push_front(1); l.push_front(2); l.push_front(3);
      l.move_to_front(a); check(l, {1,3,2}, "move last to front"); }
    { DoublyList l; l.push_front(1); l.push_front(2); DNode* c = l.push_front(3);
      l.move_to_front(c); check(l, {3,2,1}, "move front to front (no-op)"); }
    { DoublyList l; l.push_front(1); l.push_front(2); l.push_front(3);
      checkInt(l.pop_back(), 1, "pop_back returns oldest"); check(l, {3,2}, "after pop_back"); }
    { DoublyList l; l.push_front(7); checkInt(l.pop_back(), 7, "pop_back single"); check(l, {}, "empty after pop"); }
    std::cout << passed << " passed, " << failed << " failed\n";
    return failed ? 1 : 0;
}