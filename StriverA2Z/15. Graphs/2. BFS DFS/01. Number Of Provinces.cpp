#include <iostream>
#include <vector>
using namespace std;


/*
Time :  O(V^2) + O(V+E)  ~ O(V^2)

1. Build adj list from matrix  : O(V^2)
2. DFS Traversal : O(V+E)


Space : O(V+E) + O(V) + O(V)  ~ O(V^2)

1. adj list : O(V+E)
2. Vsited array : O(V)
3. Recursion stack : O(V)

worst case : complete graph => E = V(V-1)/2 ~ O(V^2)

*/
class Solution {
private:

    // Time : O(V + E)
    // Space : O(V)  (recursion stack)
    void dfs(int node, vector<vector<int>>&adj, vector<int>&visited){ // void because we're just traversing & modifying visited arr
        visited[node] = 1;

        // traversing through neighbor of connected component
        for (auto neighbor : adj[node]){
            if (!visited[neighbor]) dfs (neighbor, adj, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();  // No of vertices (legth of matrix) 

        vector<vector<int>>adj(V);  // Adjacency List

        // Converting to adjacency list
        for (int i=0; i<V; i++){ // O(V^2)
            for (int j=0; j<V; j++){
                if (isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // O(V)
        vector<int> visited(V,0); // visited array
        int count = 0; 
        for (int i=0; i<V; i++){
            if (!visited[i]){  // unvisited node
                count++;
                dfs(i, adj, visited); // node, adj list, visited arr
            }
        }
        return count;
    }
};


/*
Time Complexity:
---------------
Building adjacency list is skipped in this version.
DFS traversal checks all V neighbors for each DFS call in worst case:

    O(V^2)  (since adjacency matrix and each row scan is O(V))

Space Complexity:
----------------
Auxiliary space:
    - visited array:    O(V)
    - recursion stack:  O(V)
    => O(V)

Total space (including input matrix):
    - adjacency matrix: O(V^2)
    - auxiliary:        O(V)
    => O(V^2)

Worst case: complete graph => E = V(V-1)/2 ~ O(V^2)
*/


class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>&visited){ // void because we're just traversing & modifying visited arr
        visited[node] = 1;
        int V = isConnected.size();
        for (int i=0; i<V; i++){
            if (isConnected[node][i]==1 && !visited[i]) dfs(i, isConnected, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();  // No of vertices (legth of matrix) 

        vector<int> visited(V,0); // visited array
        int count = 0; 
        for (int i=0; i<V; i++){
            if (!visited[i]){  // unvisited node
                count++;
                dfs(i, isConnected, visited); // node, adj list, visited arr
            }
        }
        return count;
    }
};