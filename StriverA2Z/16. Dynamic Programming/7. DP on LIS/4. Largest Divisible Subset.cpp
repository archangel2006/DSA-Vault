#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end()); 
        
        int n = nums.size();

        // dp[i] = size of largest divisible subset ending at i
        vector<int> dp(n, 1); 
        vector<int> parent(n,-1); 

        int last_ind = 0;

        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[i] % nums[j] == 0){
                    if (dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > dp[last_ind]) last_ind = i;
        }
        
        vector<int> ans;
        
        while (last_ind != -1){
            ans.push_back(nums[last_ind]);
            last_ind = parent[last_ind];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;

    }
};