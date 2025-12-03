#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  private:
    bool detectCycle(int src, vector<vector<int>>& adj, vector<int>vis){
        vis[src] = 1; // source visited
        
        queue<pair<int,int>> q; // {current node, parent}
        
        q.push({src, -1}); // source node
        
        while (!q.empty()){
            int node = q.front().first; //node
            int parent = q.front().second; // where it came from
            
            q.pop();
            
            // checking all neighbor nodes
            for (auto neighbor: adj[node]){

                if (!vis[neighbor]){  //if neighbor visited, visit it
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                }else if (parent != neighbor){ // if visited and not the parent -> cycle found!!
                    return true;
                }
/*
                - We reached a node (neighbor) that was already visited.
                - But that node is NOT the parent of the current node.
                - That means we reached it from a different path → cycle detected.
*/
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // edges to adjacency list
        vector<vector<int>>adj(V);
        
        for (auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0); // visited array
        
        // Components In Graph
        for (int i=0; i<V; i++){
            if (!vis[i]){ // if not visited, start BFS here
                if (detectCycle(i, adj, vis) == true){
                    return true;
                }
            }
        }
        return false; // no cycle in any component
    }
};