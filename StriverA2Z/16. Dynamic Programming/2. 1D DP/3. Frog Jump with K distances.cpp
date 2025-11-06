#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// MEMOIZATION

class Solution {
    
  private:
    int F(int i, int k, vector<int>& height, vector<int>& dp){
        
        //Base Case
        if (i==0) return 0; // No jump, no energy used
        
        // Memoization Check
        if (dp[i] !=-1) return dp[i];
        int min_jump = INT_MAX;

        // Recursive Logic
        for(int j=1; j<=k; j++){
            if (i - j >= 0) {
                int jump = F(i - j, k, height, dp) + abs(height[i] - height[i - j]);
                min_jump = min(min_jump, jump);
            }
        }
        dp[i] = min_jump;
        return dp[i];
    }
  public:
    int minCost(int k, vector<int>& height) {
        
        int n = height.size();
        
        vector<int> dp(n, -1); // solving for index 0 to n-1
        
        return F(n-1, k, height, dp); // height i : 0 to n-1
        
        
    }
};