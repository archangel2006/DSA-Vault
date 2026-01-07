// 1161. Maximum Level Sum of a Binary Tree

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

// Time Complexity: O(N)
// Space Complexity: O(N)

// BFS Level Order Traversal : Keep track of sum at each level. Update max sum and corresponding level

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        
        if (root == NULL) return 0;

        int ans = 0;
        int max_sum = INT_MIN;

        queue<TreeNode*> q;
        q.push({root});
        
        int level=1;
        while(!q.empty()){
  
            int sum = 0;
            int n = q.size();
            for (int i=0; i<n; i++){
                TreeNode* parent = q.front();
                q.pop();
                sum+=parent->val;

                if (parent->left != NULL){
                    q.push(parent->left);
                }  
                if (parent->right != NULL){
                    q.push(parent->right);
                }
            }
            if (max_sum<sum){
                max_sum =  sum;
                ans = level;
            }
            level++;
            
        }

        return ans;
    }
};