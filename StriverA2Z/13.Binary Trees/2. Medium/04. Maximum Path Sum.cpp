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

// Time : O(N^2) because for every node we are calculating sum which is O(N)
// Space : O(N) recursive stack space O(n) + variables space O(1)

class Solution {
private:
    int FindSum(TreeNode* root){

        int sum = 0;
        if (root == NULL) return 0;

        // to handle negative values (do not take negative path)
        int left = max(0, FindSum(root->left));
        int right = max(0,FindSum(root->right));

        sum+=root->val;
        sum+=max(left, right);

        return sum;
    }

    //int max_sum = 0;
    int max_sum = INT_MIN; // default sum is 0; 
public:
    int maxPathSum(TreeNode* root) {
        if (root==NULL) return 0;

        int leftSum = FindSum(root->left);
        int rightSum = FindSum(root->right);
        // ignore negative path sum
        leftSum = max(0,leftSum);
        rightSum = max(0,rightSum);
        
        max_sum = max(max_sum, leftSum + rightSum +root->val);
        
        maxPathSum(root->left);
        maxPathSum(root->right);

        return max_sum ;   
    }
};