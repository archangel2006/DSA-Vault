#include <iostream>
#include <vector>
using namespace std;


// 1. RECURSION

// 31 / 45 testcases passed

// Time Complexity: O(2^N)
// Space Complexity: O(N) [Recursion Stack Space]

class Solution {
private:
    int F(int i){

        // Base Case
        
        if (i==0) return 1; // Reached Stair
        if (i==1) return 1; // Only 1 Stair to climb

        int climb1 = F(i-1); // Climb 1 Stair
        int climb2 = F(i-2); // Clim 2 Stairs

        return climb1+climb2; //Total num of ways to reach stair i
    }
public:
    int climbStairs(int n) {
        return F(n);
    }
};

// 2. MEMOIZATION

// Time Complexity: O(N)
// Space Complexity: O(N) + O(N) [Recursion Stack Space + DP Array

class Solution {
private:
    int F(int i, vector<int>& dp){

        // Base Case
        if (i==0 || i==1) return 1; 
        
        //Memoization Check
        if (dp[i]!=-1) return dp[i];
        
        //Recursive Call
        dp[i] = F(i-1, dp) + F(i-2, dp); 
        
        return dp[i];
    }

public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return F(n,dp);
    }
};

// 3. TABULATION

// Time Complexity: O(N)
// Space Complexity: O(N) [DP Array]

// TABULATION

class Solution {

public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        
        // Base Case
        dp[0] = 1;
        dp[1] = 1;

        // Rescursive Call Approach
        for (int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        // Return last computed value
        return dp[n];
    }
};