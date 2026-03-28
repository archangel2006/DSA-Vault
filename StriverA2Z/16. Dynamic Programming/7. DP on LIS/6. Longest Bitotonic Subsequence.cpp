#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// space Complexity: O(n)

// Approach: concept of LIS and LDS, we will calculate the length of longest increasing subsequence and longest decreasing subsequence for each index and then we will check for the maximum length of bitonic subsequence by adding the length of LIS and LDS and subtracting 1 (as the peak element is counted twice).
class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        
        vector<int> incr(n,1), dec(n,1);
        
        // LIS (left to right)
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (nums[j] < nums[i]) inc[i] = max(inc[j] + 1, inc[i]);
            }
        }
        
        // LDS (rigth to left)
        for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>i; j--){
                if (nums[j] < nums[i]) dec[i] = max(dec[j] + 1, dec[i]);
            }
        }
        
        int ans = 0;
        
        for (int i=0; i<n; i++){
            if (inc[i] > 1 && dec[i] > 1){  // valid bitonic
                ans = max(ans, inc[i] + dec[i] -1);
            }
        }
        
        return ans;
        
    }
};
