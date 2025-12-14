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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, vector<pair<int,int>>> colMap;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});
        while (!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode*  node = front.first;
            int col = front.second.second;
            int row = front.second.first;

            if (!node) continue;

            colMap[col].push_back({row, node->val});
            q.push({node->left, {row+1, col-1}});
            q.push({node->right, {row+1, col+1}});
        }

        vector<vector<int>> ans;

        for (auto &entry : colMap){
            auto &nodes = entry.second;

            sort(nodes.begin(), nodes.end());
            
            vector<int> column;

            for (auto&p : nodes){
                column.push_back(p.second);
            }

            ans.push_back(column);
        }

        return ans;
    }
};


