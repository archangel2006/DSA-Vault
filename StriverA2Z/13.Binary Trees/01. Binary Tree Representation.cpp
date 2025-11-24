#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

class Solution {
  public:

    void create_tree(node* root0, vector<int>& vec) {
        root0->left = new node();
        root0->left->data = vec[1];
        
        root0->right = new node();
        root0->right->data = vec[2];
        
        root0->left->left = new node();
        root0->left->left->data = vec[3];
        
        root0->left->right = new node();
        root0->left->right->data = vec[4];
        
        root0->right->left = new node();
        root0->right->left->data = vec[5];
        
        root0->right->right = new node();
        root0->right->right->data = vec[6];
        
    }
};