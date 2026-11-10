

//Nodes connected only from left to right, cannot go backwards
//Adding to front: O(1), new node points to the old head - head moves to the new node
//Add to back: O(N), walk until curr -> next == nullptr, then attatch. If list is empty, head is new node
//Delete: prev -> next = target -> next;
//dummy node: put fake node in front of head, making deleting the head the same as the other code





// singly.cpp  —  g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined singly.cpp -o singly && ./singly
#include <iostream>
#include <vector>

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class SinglyList {
public:
    ~SinglyList() {
        // TODO 4: free every node (walk the list, save next BEFORE deleting)
    }

    // O(1): new node becomes the head
    void push_front(int v) {
        // TODO 1
        
        Node* newNode = new Node(v);
        newNode -> next = head;    
        head = newNode;

    }

    // O(n): walk to the last node, attach the new one
    void push_back(int v) {
        // TODO 2  (careful: what if the list is empty?)

        Node* newNode = new Node(v);

        if(head == nullptr){ 
            head = newNode;
            return;
        }

        Node* curr = head;

        //while next node is not nullptr
        while(curr -> next != nullptr){ 
            //assign value of next curr node to curr
            curr = curr -> next;
        }

        curr -> next = newNode;

    }

    // Remove the FIRST node whose val == v. Return true if something was removed.
    bool remove_first(int v) {
        // TODO 3  (you need the node BEFORE the one you delete; a dummy node helps)

        Node* dummy(0);
        dummy->next = head;

        Node* prev = dummy;
        
        while(prev -> next != nullptr){ 


            if(prev -> next -> val == v){

                Node* to_delete = prev -> next;
                prev -> next = to_delete -> next; //set dummy node to node AFTER the one we want to delete
                delete to_delete;
                head = dummy -> next;
                
                return true;
             }

            prev = prev -> next;
        }

        return false;
    }

    std::vector<int> to_vector() const {
        std::vector<int> out;
        for (Node* cur = head; cur != nullptr; cur = cur->next) out.push_back(cur->val);
        return out;
    }

private:
    Node* head = nullptr;
};

// ---------------- tests (don't change) ----------------
int passed = 0, failed = 0;
void check(const std::vector<int>& got, const std::vector<int>& want, const char* name) {
    if (got == want) { passed++; return; }
    failed++;
    std::cout << "FAIL " << name << ": got [";
    for (size_t i = 0; i < got.size(); i++) std::cout << (i ? "," : "") << got[i];
    std::cout << "] want [";
    for (size_t i = 0; i < want.size(); i++) std::cout << (i ? "," : "") << want[i];
    std::cout << "]\n";
}
int main() {
    { SinglyList l; check(l.to_vector(), {}, "empty"); }
    { SinglyList l; l.push_front(1); l.push_front(2); l.push_front(3); check(l.to_vector(), {3,2,1}, "push_front x3"); }
    { SinglyList l; l.push_back(1); l.push_back(2); l.push_back(3); check(l.to_vector(), {1,2,3}, "push_back x3 (starts empty)"); }
    { SinglyList l; l.push_back(2); l.push_front(1); l.push_back(3); check(l.to_vector(), {1,2,3}, "mixed pushes"); }
    { SinglyList l; l.push_back(1); l.push_back(2); l.push_back(3);
      bool r = l.remove_first(1); check(l.to_vector(), {2,3}, "remove head"); if (!r) { failed++; std::cout << "FAIL remove head returned false\n"; } }
    { SinglyList l; l.push_back(1); l.push_back(2); l.push_back(3); l.remove_first(2); check(l.to_vector(), {1,3}, "remove middle"); }
    { SinglyList l; l.push_back(1); l.push_back(2); l.push_back(3); l.remove_first(3); check(l.to_vector(), {1,2}, "remove tail"); }
    { SinglyList l; l.push_back(5); l.push_back(5); l.remove_first(5); check(l.to_vector(), {5}, "remove only the first match"); }
    { SinglyList l; l.push_back(1); bool r = l.remove_first(9); check(l.to_vector(), {1}, "remove missing");
      if (r) { failed++; std::cout << "FAIL remove missing returned true\n"; } }
    { SinglyList l; bool r = l.remove_first(1); check(l.to_vector(), {}, "remove from empty");
      if (r) { failed++; std::cout << "FAIL remove from empty returned true\n"; } }
    std::cout << passed << " passed, " << failed << " failed\n";
    return failed ? 1 : 0;
}