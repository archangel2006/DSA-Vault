#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MEMOIZATION

// Time Complexity: O(N*N)
// Space Complexity: O(N*N) + O(N) [DP Array + Recursion Stack Space]

class Solution {
private:
    int F(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n){

        // Base Case
        if (j<0 || j>=n) return 1e9;  // boundary check
        if (i==0) return matrix[0][j];  // first row

        // Memoization Check
        if (dp[i][j]!=-1) return dp[i][j];

        // Recursion
        int leftd = matrix[i][j] + F(i-1, j-1, matrix, dp,n );
        int up = matrix[i][j] + F(i-1, j, matrix, dp, n);
        int rightd = matrix[i][j] + F(i-1, j+1, matrix, dp, n);

        return dp[i][j] = min({leftd, up, rightd});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix){

        int n = matrix.size();

        // dp initialized 
        vector<vector<int>> dp(n, vector<int>(n,-1));

        int mini = 1e9;;
        

        // The path can end at any element of the last row,
        // so we check all possible ending columns in the last row (i = n - 1)

        for (int j=0; j<n; j++){

            // Compute minimum path sum for each ending column
            mini = min(mini, F(n-1,j,matrix, dp,n));
        }

        return mini;

        
    }
};

        // int leftd = matrix[i][j] + dp[i+1][j-1];
        // int down = matrix[i][j] + dp[i+1][j];
        // int rightd = matrix[i][j] + dp[i+1][j+1];