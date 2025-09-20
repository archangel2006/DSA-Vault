#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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