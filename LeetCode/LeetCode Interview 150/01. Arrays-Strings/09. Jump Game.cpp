#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach: Greedy

// Explanation: We start from the end of the array and keep track of the "goal" position we need to reach.
// If from the current position we can jump to or beyond the goal, we update the goal to the current position.
// If we can move the goal all the way back to the start of the array, then we can reach the end from the start.

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        
        int i=n-1; int goal = n-1;

        while (i>=0){
            if (i+nums[i] >= goal){ // if jump to goal is feasible
                goal = i;
                //i--;
            }
            i--;
            //else return false;
        }
        if (goal == 0) return true; // if reached start point
        else return false;

    }
};