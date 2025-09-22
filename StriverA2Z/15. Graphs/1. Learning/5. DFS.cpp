#include <iostream>
#include <vector>
using namespace std;

class Solution {
  private:
    void dfsHelper(int node, vector<vector<int>>& adj, int vis[], vector<int>& result ){
        vis[node] = 1;
        result.push_back(node);
        for (auto neighbor : adj[node]){
            if (!vis[neighbor]){
                dfsHelper(neighbor, adj, vis, result);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
 
        int V = adj.size(); 
        int vis[V] = {0};
        vis[0] = 1;
        int start = 0;
        vector<int> result;
        dfsHelper(start, adj, vis, result );
        return result;
    }
    
};