#include <iostream>
using namespace std;
#include <vector>

// Representation of a node
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};


class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        if (arr.empty()) return NULL;
        
        Node* head = new Node(arr[0]);
        Node* curr = head;
        
        for (size_t i = 1; i<arr.size(); i++) {
            curr->next = new Node(arr[i]);
            curr = curr->next;
        }
    
        return head;
    }
    
};

// Time: 0.25sec


/* What is size_t in C++?
- size_t is an unsigned integer type (only stores 0 or positive values).
- It is defined in the standard library (<cstddef> or indirectly through <vector>, <string>, etc.).
- It is used to represent sizes and indices of containers (like vector, string, array).

So whenever we call something like: arr.size()
the return type is size_t, not int.
*/