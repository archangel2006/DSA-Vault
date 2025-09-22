#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        
        int n = adj.size();
        int vis[n] = {0};
        queue <int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> result;
        
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto it : adj[node]){
                if (!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return result;
        
    }
};