#include <iostream>
#include <vector>
using namespace std;


// 37 / 42 testcases passed

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));                                               

        // Base Case
        dp[0][0] = 1;

        // Recursion
        for (int i=0; i<=m-1; i++){
            for (int j=0; j<=n-1; j++){

                if (i == 0 && j == 0) continue; // Base Case already handled

                int up = 0, left = 0;       
                
                if (obstacleGrid[i][j] != 1){
                    if (i>0) up = dp[i-1][j]; 
                    if (j>0) left = dp[i][j-1];
                }
                
                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
};


// 40 / 42 testcases passed


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));                                               


        // Base Case
        if ((m==1 || n==1) && obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;

        // Recursion
        for (int i=0; i<=m-1; i++){
            for (int j=0; j<=n-1; j++){

                if (i == 0 && j == 0) continue; // Base Case already handled

                int up = 0, left = 0;       
                
                if (obstacleGrid[i][j] != 1){
                    if (i>0) up = dp[i-1][j]; 
                    if (j>0) left = dp[i][j-1];
                }
                
                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
};


// Time Complexity: O(m*n)
// Space Complexity: O(m*n) (dp array)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));                                               


        // Base Case
        if ((m==1 || n==1) && obstacleGrid[0][0] == 1) return 0;

        if (obstacleGrid[0][0] == 1) dp[0][0] = 0;
        else dp[0][0] = 1;

        // Recursion
        for (int i=0; i<=m-1; i++){
            for (int j=0; j<=n-1; j++){

                if (i == 0 && j == 0) continue; // Base Case already handled

                int up = 0, left = 0;       
                
                if (obstacleGrid[i][j] != 1){
                    if (i>0) up = dp[i-1][j]; 
                    if (j>0) left = dp[i][j-1];
                }
                
                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
};