#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity: O(V + E) + O(V) + O(V) ~ O

class Solution {
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V);
        int ind[V] = {0};
        queue<int> q;
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
             
            adj[u].push_back(v); // directed graph
            ind[v]++;
        }
        
        // adding elements with indegree = 0
        for (int i=0; i<V; i++){
            if (ind[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (auto neighbor : adj[node]){
                ind[neighbor]--;
                if (ind[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }
};