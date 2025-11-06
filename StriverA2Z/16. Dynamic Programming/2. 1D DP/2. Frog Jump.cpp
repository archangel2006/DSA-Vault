#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// MEMOIZATION
class Solution {
    
  private:
    int F(int i,vector<int>& height, vector<int>& dp){
        
        //Base Case
        if (i==0) return 0; // No jump, no energy used
        
        // Memoization Check
        if (dp[i] !=-1) return dp[i];
        


        // Recursive Calls
        int jump1 = F(i-1,height, dp) + abs(height[i] - height[i-1]);
        int jump2 = INT_MAX;
        if (i > 1){
            jump2 = F(i-2,height, dp) + abs(height[i] - height[i-2]);
        }
        
        dp[i] = min( jump1, jump2);
        return dp[i];
    }
  public:
    int minCost(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> dp(n, -1); // solving for index 0 to n-1
        
        return F(n-1, height, dp); // height i : 0 to n-1
        
        
    }
};