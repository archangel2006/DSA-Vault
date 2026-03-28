#include <bits/std.c++.h>
using namespace std;


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
          
        int n = nums.size();
        vector<int> dp(n,1);
        int len = 0;

        vector<int> cnt(n, 1);

        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[j] < nums[i]){
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];     // found 1 sequence through j
                    }
                    else if (dp[j] + 1 == dp[i]){  // another sequence which gets same sequence
                        cnt[i] += cnt[j];
                    }
                }
            }
            len = max(len, dp[i]);
        }
        
        int ans = 0;
        for (int i=0; i<n; i++){
            if (dp[i] == len){
                ans += cnt[i];
            }
        }
        return ans;
        
    }
};