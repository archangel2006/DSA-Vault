#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));                                               


        // Base Case
        dp[0][0] = grid[0][0];

        // Recursion
        for (int i=0; i<=m-1; i++){
            for (int j=0; j<=n-1; j++){

                if (i == 0 && j == 0) continue; // Base Case already handled

                int up = INT_MAX, left = INT_MAX;      
                if (i>0) up = dp[i-1][j] + grid[i][j]; 
                if (j>0) left = dp[i][j-1] + grid[i][j];
                
                dp[i][j] = min(up,left);
            }
        }
        return dp[m-1][n-1];
        
    }
};