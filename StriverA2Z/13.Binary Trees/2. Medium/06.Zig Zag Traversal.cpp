#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> tree;
            if (root == NULL) return tree;

            queue<TreeNode*> q;
            q.push({root});
            tree.push_back({root->val});

            int level =0;

            while(!q.empty()){
    
                vector<int> level;
                int n = q.size();
                for (int i=0; i<n; i++){
                    TreeNode* parent = q.front();
                    q.pop();

                    if (parent->left != NULL){
                        q.push(parent->left);
                        level.push_back(parent->left->val);
                    }  
                    if (parent->right != NULL){
                        q.push(parent->right);
                        level.push_back(parent->right->val);
                    }
                }
                if (!level.empty()) tree.push_back(level);
            }

            return tree;
        }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>tree = levelOrder(root);

        for (int i=0; i<tree.size(); i++){
            if (i%2!=0){
                reverse(tree[i].begin(), tree[i].end());
            }
        }
        return tree;
    }
};