#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    vector<int> bottomView(Node *root) {

        map<int, int> mp;
        queue<pair<Node*, int>> q;
    
        q.push({root, 0});
    
        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
    
            // override column value till last node is stored
            
            mp[col] = node->data;
    
            if (node->left)  q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }
    
        vector<int> ans;
        for (auto &x : mp) ans.push_back(x.second);
        return ans;
    }
    
};