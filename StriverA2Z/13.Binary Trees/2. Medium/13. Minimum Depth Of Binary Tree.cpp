#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
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
    //check if node is leaf node
    bool isLeaf(TreeNode *node){
        return node->left == nullptr && node->right == nullptr;
    }
    
public:
    int minDepth(TreeNode* root) {
     
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push({root});
        
        int level =1;

        while(!q.empty()){

            int n = q.size();
            for (int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                if (isLeaf(node)) return level;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
/*
                if (parent->left != NULL){
                    q.push(parent->left);
                    if (isLeaf(parent->left)) return level;
                }  
                if (parent->right != NULL){
                    q.push(parent->right);
                    if (isLeaf(parent->right)) return level;
                }
*/
            }
            level++;
            
        }

        return level;
        
    }
};