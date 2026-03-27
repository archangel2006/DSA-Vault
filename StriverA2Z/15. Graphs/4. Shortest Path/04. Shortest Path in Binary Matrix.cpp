#include <bits/stdc++.h>
using namespace std;


// Solution 1: {row, col, distance} in queue

// Time Complexity: O(n^2) in worst case, when all cells are 0
// Space Complexity: O(n^2) in worst case, when all cells are 0

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // if start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // 8 directions
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};

        queue<tuple<int,int,int>> q;  // row, col, distance

        q.push({0,0,1});
        grid[0][0] = 1;  //mark visited

        while(!q.empty()){

            auto [row, col, distance] = q.front();
            q.pop();

            // if reached destination
            if (row == n-1 && col == n-1) return distance;

            // otherwise traverse
            for (auto [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0){
                    q.push({nr, nc, distance + 1});
                    grid[nr][nc] = 1; // mark visited
                }
            }
        }

        return -1; // no path found

    }
};



// Solution 2: Level Order Traversal (bfs), {row, col} in queue, distance is tracked by level

// Time Complexity: O(n^2) in worst case, when all cells are 0
// Space Complexity: O(n^2) in worst case, when all cells are 0
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // if start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // 8 directions
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};

        queue<pair<int,int>> q;  // row, col
        int distance = 1; // (0,0)

        q.push({0,0});
        grid[0][0] = 1;  //mark visited

        while(!q.empty()){

            int size = q.size(); //number of nodes in this level
            while (size--){

                auto [row,col] = q.front();
                q.pop();

                // if reached destination
                if (row == n-1 && col == n-1) return distance;

                // otherwise traverse
                for (auto [dr, dc] : directions){
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0){
                        q.push({nr, nc});
                        grid[nr][nc] = 1; // mark visited
                    }
                }
            }
            // after traversing one full level
            distance++; 

        }

        return -1; // no path found

    }
};