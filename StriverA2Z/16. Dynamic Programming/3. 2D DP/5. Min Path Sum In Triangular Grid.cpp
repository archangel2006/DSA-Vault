#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// MEMOIZATION

// 27 / 46 testcases passed

// Time Complexity: O(N^2)
// Space Complexity: O(N^2) + O(N)  (for dp array and recursion stack)

class Solution {
private:
    int F(int i,int j, int n, vector<vector<int>>& dp, vector<vector<int>>& triangle){
         
        // Base Case
        if (i==n-1) return dp[i][j] = triangle[n-1][j]; // reach the last row
        
        // Meoization Check
        if (dp[i][j]!=-1) return dp[i][j];

        // Recursion
        int down = triangle[i][j] + F(i+1,j,n,dp,triangle); 
        int diag = triangle[i][j] + F(i+1, j+1,n,dp,triangle);

        return dp[i][j] = min(down, diag); // min of both moves and store it
    }

public:
    int minimumTotal(vector<vector<int>>& triangle){ 
        int n = triangle.size();
        
        // dp[i][j] will store the minimum path sum starting from cell (i, j)

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return F(0,0,n,dp,triangle); // Start from the top element (0, 0)
    }
};

// TABULATION 

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)  (for dp array)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // create n x n dp table
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // STEP 1: base case : copy last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // STEP 2: fill bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }

        // STEP 3: top cell holds the answer
        return dp[0][0];
    }
};
