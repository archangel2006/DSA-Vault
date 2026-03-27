#include <bits/stdc++.h>
using namespace std;]


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// 1011 /1111 test cases passed

class Solution {
  public:
    vector<int> topView(Node *root) {
        
        // map<int, vector of (row, value)>
        map<int, vector<pair<int,int>>> MAP;
        
        // queue (node, row, column)
        queue<pair<Node*, pair<int,int>>> q;


        q.push({root, {0,0}});
        
        while (!q.empty()){
            auto parent = q.front(); // first node
            q.pop();
            
            Node* parent_node = parent.first;
            int row = parent.second.first;
            int col = parent.second.second;
            
            if (!parent_node) continue;
            
            MAP[col].push_back({row,parent_node->data});
            
            q.push({parent_node->left, {row+1, col-1}});
            q.push({parent_node->right, {row+1, col+1}});
        }
        
        vector<vector<int>> tree;
        
        // process columns from left to right
        for (auto &entry : MAP){
            auto &nodes = entry.second;
            
            // sort by row first, value second
            sort(nodes.begin(), nodes.end());
            
            vector<int> column;
            for (auto &x : nodes){
                column.push_back(x.second);
            }
            
            tree.push_back(column);
        }
        
        vector<int> ans;
        for (auto val : tree){
            ans.push_back(val[0]);
        }
        
        return ans;
        
    }
};

// all test case passed


class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int, int> mp;
        queue<pair<Node*, int>> q;
    
        q.push({root, 0});
    
        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
    
            // FIRST node per column = top view
            if (mp.find(col) == mp.end())
                mp[col] = node->data;
    
            if (node->left)  q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }
    
        vector<int> ans;
        for (auto &x : mp) ans.push_back(x.second);
        return ans;
    }
    
};