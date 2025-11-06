#include <iostream>
#include <vector>
using namespace std;


// LOOPs

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
  public:
    int nthFibonacci(int n) {
        
        // Base Case
        if (n==0) return 0;
        if (n==1) return 1;
        
        int prev1 = 0; //Fib(0)
        int prev2 = 1; //Fib(1)
        int curr;
        
        for (int i=2; i<=n; i++){  // Start For Loop from 2
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        
        return curr;
        
    }
};

// RECURSION + MEMOIZATION

// Time Complexity: O(N)
// Space Complexity: O(N) + O(N) [Recursion Stack Space + DP Array

class Solution {
  private:
    int F(int i, vector<int>& dp){
        
        // Base Case
        if (i==0) return 0;
        if (i==1) return 1;
        
        // Memoization Check
        if (dp[i]!=-1) return dp[i];
        
        // Recursive Call
        dp[i] = F(i-1, dp) + F(i-2, dp);
        
        return dp[i];
        
    }
  public:
    int nthFibonacci(int n) {
        vector<int>dp(n+1,-1);
        return F(n,dp);
    }
};