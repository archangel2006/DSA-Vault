#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        while (i<nums.size()){ // O(n)
            if (nums[i] == val){
                nums.erase(nums.begin() + i); //Delete the element at index i from the vector nums.
                // erase : O(n) - shifting of rest of the elements
            }
            else{
                i++;
            }
        }
        return nums.size();
    }
};