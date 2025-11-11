#include <iostream>
#include <vector>
using namespace std;

// RECURSION

// 42 / 64 testcases passed

// Time Complexity: O(2^(m+n))
// Space Complexity: O(m+n)  (recursive stack space)

class Solution {
private:
    int F(int i, int j){
        
        //Base Case
        if (i==0 && j==0) return 1; // count 1 if path is reached
        if (i<0 || j<0) return 0;  //out of bounds 

        int up = F(i-1,j);  // go up
        int left = F(i, j-1); // go left

        return up+left;
    }
public:
    int uniquePaths(int m, int n) {
        return F(m-1,n-1);
        
    }
};

// Dynamic Programming

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) + O(m+n) (dp array + recursive stack space)

class Solution {
private:
    int F(int i, int j, vector<vector<int>>& dp){
        
        //Base Case
        if (i==0 && j==0) return 1; // count 1 if path is reached
        if (i<0 || j<0) return 0;  //out of bounds 

        // Memoization Check
        if (dp[i][j]!=-1) return dp[i][j];

        // Recursive Calls
        int up = F(i-1,j, dp); 
        int left = F(i, j-1, dp); 

        return dp[i][j] = up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return F(m-1,n-1, dp);   
    }
};

// Tabulation

// Time Complexity: O(m*n)
// Space Complexity: O(m*n) (dp array)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));                                               

        // Base Case
        dp[0][0] = 1;

        // Recursion
        for (int i=0; i<=m-1; i++){
            for (int j=0; j<=n-1; j++){

                if (i == 0 && j == 0) continue; // Base Case already handled

                int up = 0, left = 0;       
                
                if (i>0) up = dp[i-1][j]; 
                if (j>0) left = dp[i][j-1];
                
                dp[i][j] = up+left;
            }
        }
         
        return dp[m-1][n-1];  
    }
};