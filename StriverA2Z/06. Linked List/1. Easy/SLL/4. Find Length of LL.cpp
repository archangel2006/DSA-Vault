#include <iostream>
#include <vector>
using namespace std;


class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        Node* curr = head;
        int cnt = 0;
        
        while (curr != nullptr){
            cnt++;
            curr = curr->next;
        }
        
        return cnt;
    }
};

//Time : 0.05sec