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


// 101 / 106 testcases passed

class Solution {
private:
    int Height(TreeNode* root){

        int height = 0;
        if (root == NULL) return 0;

        height++;
        height+=max(Height(root->left), Height(root->right));

        return height;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int left = Height(root->left);
        int right = Height(root->right);
        return left + right;
        
    }
};


// All testcases passed

// Time : O(N^2) because for every node we are calculating height which is O(N)
// Space : O(N) recursive stack space O(n) + variables space O(1)
class Solution {
private:
    int Height(TreeNode* root){

        int height = 0;
        if (root == NULL) return 0;

        height++;
        height+=max(Height(root->left), Height(root->right));

        return height;
    }

    int diameter = 0; 
 
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL) return 0;

        // only for path passing through root
        int left = Height(root->left);
        int right = Height(root->right);
        diameter = max(diameter, left + right);  

        // computing internal diameters 
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return diameter;
        
    }
};