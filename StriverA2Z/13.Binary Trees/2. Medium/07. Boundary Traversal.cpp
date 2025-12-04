/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
  
    // 1. check if node is leaf node
    bool isLeaf(Node *node){
        return node->left == nullptr && node->right == nullptr;
    }
    
    
    // 2. traverse leftmost tree nodes  
    void collectLeft(Node *root, vector<int>& result){
        
        // if root is leaf or null
        if (root == nullptr || isLeaf(root)) return;
        
        // if root is not null and not a leaf, add it's value
        result.push_back(root->data); 
        
        // collect left subtree left nodes 
        if (root->left) collectLeft(root->left, result);
        // if no left subtree collect leftmost nodes of right subtree
        else if (root->right) collectLeft(root->right, result);
    }
    
    
    // 3. collect all leaf nodes
    void collectLeaves(Node *root, vector<int>& result){
        
        // if root is null 
        if (root==nullptr) return;
        
        // if root is leaf node
        if (isLeaf(root)){
            result.push_back(root->data);
            return;
        }
        
        // collect all leaf nodes 
        collectLeaves(root->left, result);
        collectLeaves(root->right, result);
    }
    
    // 4. traverse rightmost tree nodes
    void collectRight(Node *root, vector<int>& result){
        
        // if root is null or leaf node
        if (root == nullptr || isLeaf(root)) return;
        
        // collect right subtree right nodes
        if (root->right) collectRight(root->right, result);
        // collect left subtree left nodes
        else if (root->left) collectRight(root->left, result);
        
        // add root
        result.push_back(root->data);
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> result;
        
        if(!root) return result;
        
        if (!isLeaf(root)) result.push_back(root->data);
        
        collectLeft(root->left, result);
        
        collectLeaves(root, result);
        
        collectRight(root->right, result);
        
        return result;
        
    }
};