#include <iostream>
#include <vector>
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


// 203 / 228 testcases passed

class Solution {
private:
    int maxDepth(TreeNode* root) {

        int height = 0;
        if (root == NULL) return 0;

        // Add root
        height++;

        //Branch Traversal
        height+=max(maxDepth(root->left),maxDepth(root->right));

        return height;
    }
public:
    bool isBalanced(TreeNode* root) {

        if (root == NULL) return true;

        //Branch Traversal
        int right_height = maxDepth(root->right);
        int left_height = maxDepth(root->left);

        return (abs(left_height - right_height)<=1);
        
    }
};