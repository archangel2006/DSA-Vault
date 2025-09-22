#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        
        int E = edges.size();
        vector<vector<int>> adj(V); // index for each vertex
        for (int i=0; i<E; i++){ // loops over number of edges
            int u,v;
            u = edges[i].first;
            v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
};

// Time : 0.04s