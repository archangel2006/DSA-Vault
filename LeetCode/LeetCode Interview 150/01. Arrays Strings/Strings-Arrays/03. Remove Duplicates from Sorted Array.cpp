#include <bits/stdc++.h>
using namespace std;


// BRUTE FORCE APPROACH

// Time Complexiy : O(n^2)
// Space Complexity : O(n) - for unordered set

class Solution {
public:
    int removeDuplicates(vector<int>& nums){ 
        unordered_set<int> S;  // set for unique elements

        int i = 0;

        // iterate through nums 
        while(i<nums.size()){  // O(n)
            int num = nums[i];

            // if number is not in set, add it
            if (S.find(num) == S.end()){  // O(1)
                S.insert(num); 
                i++;
            }
            else{
                // remove repeated number from nums
                nums.erase(nums.begin() + i);  // O(n)
            }
        }
        
        return nums.size();
    }
};


// OPTIMIZED APPROACH

// Time Complexiy : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums){ 
        int overwrite = 1; // variable count of unique values
        // tells us where to overwrite next unique number

        for (int i=1; i<nums.size(); i++){
            if (nums[i]!=nums[i-1]){  // if a new number found
                nums[overwrite] = nums[i]; // overwrite it after the previous valid num
                overwrite++; // move index
            }

        }
        return overwrite;
    }
};