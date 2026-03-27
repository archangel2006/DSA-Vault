#include <bits/stdc++.h>
using namespace std;


// DFS APPROACH

// Time Complexity: O(V + E) where V is number of vertices and E is number of edges
// Space Complexity: O(V) for color array + O(V) for recursion stack = O(V)

class Solution {
private:
    
    bool dfs(int node, int curr_color, vector<int>& color, vector<vector<int>> graph){

        // color the current node
        color[node] = curr_color;  
        
        // iterate through neighbors
        for (auto neighbor : graph[node]){

            // if graph not colored
            if (color[neighbor] == -1){

                // color it with opposite color, also color its branch
                if (dfs(neighbor, !curr_color, color, graph) == false) return false;
            }

            // if color of neighbor is same as node, return false
            if (color[neighbor] == curr_color) return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size(); // number of vertices

        vector<int>color(V,-1); // initialize color vector

        // connected components dfs
        for (int i = 0; i<V; i++){

            // if after dfs, bipartite is false
            if (color[i] == -1){
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }

        return true;

    }
};


// BFS APPROACH

// Time Complexity: O(V + E) where V is number of vertices and E is number of edges
// Space Complexity: O(V) for color array + O(V) for queue = O(V

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size(); // number of vertices

        vector<int>color(V,-1); // initialize color vector

        // connected components bfs
        for (int i = 0; i<V; i++){

            // if not colored
            if (color[i] == -1){

                color[i] = 0; 

                queue<int>q;
                q.push(i); // push node

                // bfs
                while(!q.empty()){

                    int node = q.front();
                    q.pop();

                    for(int neighbor : graph[node]){
                        
                        // if neighbor not colored
                        if (color[neighbor] == -1){
                            color[neighbor] = 1-color[node];
                            q.push(neighbor);
                        }

                        // if same color
                        else if (color[neighbor] == color[node]) return false;
                    }
                }

            }
        }

        return true;

    }
};