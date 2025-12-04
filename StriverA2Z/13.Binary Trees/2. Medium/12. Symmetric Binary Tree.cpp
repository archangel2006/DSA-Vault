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


// Time Complexity: O(N) + O(N) + O(N) = O(N)  Left subtree traversal + Right subtree traversal + Vector insert/copy operations

// Space Complexity: O(N) + O(N) + O(H) = O(N)  Left traversal vector + Right traversal vector + Recursion call stack (H = height of tree)

// → Worst case (skewed tree): O(N + N + N) = O(N)
// → Best case (balanced tree): O(N) space dominated by traversal vectors


class Solution {
private:
    vector<string>leftTraversal(TreeNode* root) {

        vector<string>ans;

        if (root == NULL){
            ans.push_back("null");
            return ans;
        } 

        // Add root
        ans.push_back(to_string(root->val));

        // Left Branch Traversal
        vector<string>left = leftTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        // Right Branch Traversal
        vector<string>right = leftTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }

    vector<string>rightTraversal(TreeNode* root) {

        vector<string>ans;

        if (root == NULL){
            ans.push_back("null");
            return ans;
        } 

        // Add root
        ans.push_back(to_string(root->val));

        // Right Branch Traversal
        vector<string>right = rightTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        // Left Branch Traversal
        vector<string>left = rightTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        return ans;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        vector<string>left = leftTraversal(root->left); 
        vector<string>right = rightTraversal(root->right);

        //reverse(right.begin(), right.end());
        return left == right;    
        
    }
};