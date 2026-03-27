#include<iostream>
#include<vector>
#include<climits>

using namespace std;


// Solution 1: DFS with backtracking

// Time Complexity: O(4^(m*n)) in worst case, where m and n are dimensions of the grid
// Space Complexity: O(m*n) for visited array and recursion stack

// 15 / 76 testcases passed
class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited, int currentMax, int& globalMin){

        int rows = heights.size();
        int cols = heights[0].size();

        // Prune if already worse than best answer
        if (currentMax >= globalMin) return;

        // If destination reached
        if (r == rows - 1 && c == cols - 1){
            globalMin = currentMax;
            return;
        }

        visited[r][c] = true; // marks current cell visited

        // 4 directions
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        // Check bounds and not visited
        for (int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr <= rows -1 && nc <= cols - 1 && !visited[nr][nc]){

                // Effort to move to next cell
                int diff = abs(heights[r][c] - heights[nr][nc]);
                // Update max effort for this path
                int newMax = max(currentMax, diff);

                dfs(nr, nc, heights, visited, newMax, globalMin);
            }
        }
        visited[r][c] = false; // for backtracking
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        int globalMin = INT_MAX;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        dfs(0, 0, heights, visited, 0, globalMin);

        return globalMin;
    }
};