#iclude <std/bits++.h>


// OPTIMIZED APPROACH

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int overwrite = 1; // index to know where reqd number ends
        int cnt = 1; // freq of curent num

        for (int i=1; i<nums.size(); i++){
            if (nums[i] == nums[i-1]){ // if same number, increase count
                cnt++;
            }
            else{ // if new number, new count 1
                cnt = 1; 
            }

            if (cnt<=2){ // if count after update is still less than/equal to 2 
                nums[overwrite] = nums[i]; // overwrite as new num
                overwrite++; // move pointer to next
            }
        }

        return overwrite;
        
    }
};