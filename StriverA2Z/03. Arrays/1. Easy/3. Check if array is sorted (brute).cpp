#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Brute Force Approach
// Approach: Rotate the array from 0 to k times and check if it is sorted after each rotation.
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        int k = 0;
        int i = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[k]) {
                k = i;
            }
        }

        // while (i<n-1){
        //     if (nums[i]<nums[i+1]){
        //         k = i;
        //     }else{
        //         k = i+1;

        //     i+=1;
        // }

        int prev = nums[0];
        while (k>0){
            for (int i=1; i<n; i++ ){
                int curr = nums[i];
                nums[i] = prev;
                prev = curr;
            }
            nums[0] = prev;
            k--;
        }

        if (is_sorted(nums.begin(), nums.end())){
            return true;
        }else{
            return false;
        }     
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)

// Optimized Approach
// Approach: Find the minimum element and rotate the array to make it sorted.


// 108 / 112 testcases passe
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int>rotated(n);

        int min_val = INT_MAX;
        int k = 0;

        for (int i=0; i<n; i++){
            if (min_val > nums[i]){
                k = i;
                min_val = nums[i];
            } 
        }

        for (int i=0; i<n; i++){

            int new_i = (i-k+n)%n;
            rotated[new_i] = nums[i];

        }

        for (int i=0; i<n-1; i++){
            if (rotated[i] > rotated[i+1]) return false;
        }

        return true;
    }
};


// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Approach: Find all indices of minimum element and check for sorted array for all rotations.
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int>rotated(n);

        int min_val = INT_MAX;
        int k = 0;

        // 1. Find min value
        for (int i=0; i<n; i++){

            min_val = min(min_val, nums[i]);

            /*if (min_val > nums[i]){
                k = i;
                min_val = nums[i];
            */ 
        }

        vector<int> mins;

        // 2. Stor all min_val indices
        for (int i=0; i<n; i++){
            if (nums[i] == min_val) mins.push_back(i);
        }

        // 3. Check if sorted for all rotations
        for (int k : mins){
            for (int i=0; i<n; i++){

                int new_i = (i-k+n)%n;
                rotated[new_i] = nums[i];

            }

            bool sorted = true;
            for (int i=0; i<n-1; i++){
                if (rotated[i] > rotated[i+1]){
                    sorted = false;
                    break;
                }
            }
            
            if (sorted) return true;
        }

        return false;
    }
};