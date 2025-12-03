#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1010/1051 test cases passed

class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& component){
        vis[node] = 1;
        component.push_back(node);
        
        for (auto neighbor : adj[node]){
            if (!vis[neighbor]){
                dfs(neighbor, adj, vis, component);
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        // for (int i=0; i<V; i++){
        //     int u,v;
        //     u = edges[i][0];
        //     v = edges[i][1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        }
        
        //int vis[V] = {0};
        
        vector<int> vis(V,0);
        vector<vector<int>>components;
        
        for (int i=0; i<V; i++){
            if (!vis[i]){
                cnt++
                vector<int> component;
                dfs(i, adj, vis, component);
                components.push_back(component);
            }
        }
        return cnt;
        
        
    }
};
