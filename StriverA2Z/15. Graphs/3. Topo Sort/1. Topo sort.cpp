#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V) + O(V) for stack + O(V) for visited array

class Solution {
    
  private:
    void dfs (int node, stack<int>& st, int vis[], vector<vector<int>>& adj){
        vis[node] = 1;
        for (auto neighbor: adj[node]){
            if (!vis[neighbor]) dfs(neighbor, st, vis, adj);
        }
        st.push(node);
    }
  
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V);
        int vis[V] = {0};
        stack<int> st;
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
             
            adj[u].push_back(v); // directed graph
            //adj[v].push_back(u);
        }
        
        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfs(i, st, vis, adj);
            }
        }
        
        vector<int>ans;
        
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};