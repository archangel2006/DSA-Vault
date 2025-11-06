#include <iostream>
#include <vector>
using namespace std;

// MEMOIZATION

//Time Complexity: O(N)
//Space Complexity: O(N) + O(N) [Recursion Stack Space + DP Array

class Solution {
private:
    int F(int i, vector<int>& nums, vector<int>& dp){

        // Base Case
        if (i==0) return nums[0];
        if (i<0) return 0;

        // Memoization Check
        if (dp[i]!=-1) return dp[i];

        // Recursive Call
        int rob = nums[i] + F(i-2, nums, dp);
        int dont_rob = 0 + F(i-1, nums, dp);

        dp[i] = max(rob, dont_rob);

        return dp[i];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Create seperate DP vectors for both cases
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        // edge case: If 1 house available, we can't remove element from start or end
        if (n==1) return nums[0];

        // Create 2 cases vector
        vector<int> temp1(nums.begin(), nums.end()-1); //exclude last element
        vector<int> temp2(nums.begin()+1, nums.end()); //exclude first element
    
        // Return Max obtained from both cases
        return max(F(n-2, temp2, dp2), F(n-2, temp1, dp1));
    }
};