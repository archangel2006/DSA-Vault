#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 108/112 test cases passed
// nums = [6,10,6]
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
    // 1.Find index of minimum element 
        int k=0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[k]) {
                k = i;
            }
        }

    // 2. Rotate the array left by k using temporary array
        
        while (k>0){
            int first = nums[0];
           
            for (int i=0; i<n-1; i++ ){
                int curr = nums[i];
                nums[i] = nums[i+1];
            }
            nums[n-1] = first;
            k--;
        }

        if (is_sorted(nums.begin(), nums.end())){
            return true;
        }else{
            return false;
        }     
    }
};