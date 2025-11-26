#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
 


// Approach: Recursion
// Time Complexity: O(N)
// Space Complexity: O(H)  (H is height of tree)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == NULL) return ans;

        // Left Branch Traversal
        vector<int>left = inorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        // Add Root
        ans.push_back(root->val);

        // Right Branch Traversal
        vector<int>right = inorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
        
    }
};