#include <iostream>
#include <vector>
using namespace std;

// RECURSION

// 55 / 70 testcases passed

// Time Complexity: O(2^N)
// Space Complexity: O(N) [Recursion Stack Space]

class Solution {
private:
    int F(int i, vector<int>& nums){

        // Base Case
        if (i==0) return nums[0];
        if (i<0) return 0;

        // Recursive Call
        int rob = nums[i] + F(i-2, nums);
        int dont_rob = 0 + F(i-1, nums);

        return max(rob, dont_rob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return F(n-1, nums);
    }
};

// MEMOIZATION

// Time Complexity: O(N)
// Space Complexity: O(N) + O(N) [Recursion Stack Space + DP Array

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
        vector<int>dp(n+1,-1);
        return F(n-1, nums, dp);
    }
};