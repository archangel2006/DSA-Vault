#include <iostream>
using namespace std;
#include <vector>


class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if (head == nullptr) return new Node(x);


        Node* curr = head;
        Node* new_node = new Node(x); 
        
        while (curr->next !=nullptr){
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->next = nullptr;
        
        return head;
        
    }
};

// Time: 0.18 sec