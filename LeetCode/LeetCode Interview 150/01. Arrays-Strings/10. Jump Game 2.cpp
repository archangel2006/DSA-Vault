#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach: Greedy

// Explanation: We keep track of the farthest point we can reach as we iterate through the array.
// When we reach the end of the current range (currEnd), we increment the jump count 
  
class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int jumps = 0;

        int currEnd = 0;
        int farthest = 0;

        for (int i=0; i<n-1; i++){
            farthest = max(farthest, i+nums[i]);

            // when current range ends, we must jump
            if (i == currEnd){
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;


        
    }
};