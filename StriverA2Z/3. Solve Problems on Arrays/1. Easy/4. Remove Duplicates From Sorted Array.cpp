#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int curr = 1;
        int val = nums[0];
        while (curr < n){
            if (nums[curr] == val){
                curr++;
            }else{
                i++;
                swap(nums[curr], nums[i]);
                curr+=1;
                val = nums[i];
            }
        }
        return i+1;
        
    }
};

// Time : 0ms