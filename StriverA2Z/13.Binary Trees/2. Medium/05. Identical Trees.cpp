#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    vector<string> Traversal(TreeNode* root){
        vector<string> tree;
        if (root == NULL){
            tree.push_back("null");
            return tree;
        }
        tree.push_back(to_string(root->val));
        vector<string>left = Traversal(root->left);
        tree.insert(tree.end(), left.begin(), left.end());
        vector<string>right = Traversal(root->right);
        tree.insert(tree.end(), right.begin(), right.end());

        return tree;

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return Traversal(p) == Traversal(q); 
        
    }
};