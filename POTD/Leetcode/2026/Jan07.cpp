// 1339. Maximum Product of Splitted Binary Tree


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
 

 // RECURSIVE APPROACH

/*
- So basically divide into 2 halved with max sum...

**Brute force**: 
- Use recursive approach to split into 2 parts, calculating sum of each part and multiplying
- store a global max_product variable and update each time
*/

// Time Complexity: O(N) where N is number of nodes in the binary tree
// Space Complexity: O(H) where H is height of the binary tree

class Solution {
private:
    long long total_tree_sum;
    long long max_product;

    int total_sum(TreeNode* root){

        if (root == NULL) return 0;
        return root->val + total_sum(root->left) + total_sum(root->right);

    }
    
    int subtree_sum(TreeNode* node){

        if (node == NULL) return 0;

        int left = subtree_sum(node->left);
        int right = subtree_sum(node->right);

        int curr_sum = node->val + left + right;

        long long product = 1LL*curr_sum*(total_tree_sum - curr_sum);

        max_product = max(max_product, product);

        return curr_sum;
        
    }
public:

    int maxProduct(TreeNode* root) {
        
        total_tree_sum = total_sum(root);
        max_product = 0;

        subtree_sum(root);

        return max_product%(1000000007);
    }
};



/*

EXPLANAYION:

**Brute force**: 
- Use recursive approach to split into 2 parts, calculating sum of each part and multiplying
- store a global max_product variable and update each time

	**STEP1**  : Understand what recursion should return
	- What does the function return to its parent?
	- Return sum of subtree rooted at this node

**STEP2** : Where do you compute the product?
1. At a node:
	- sum of left subtree
	- sum of right subtree
2. Cut edge b/w edge and parent node: 2 subtrees
	- curr_subtree_sum
	- total_tree_sum - curr_subtree_sum
3. global max_product updates here

*/
