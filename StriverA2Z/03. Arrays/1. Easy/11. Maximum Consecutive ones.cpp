#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int max_count = 0;
        int n = nums.size();
        int i =0;
        while (i<n){
            if (nums[i]==1){
                cnt++;
            }else if (nums[i]==0){
                max_count = max(max_count, cnt);
                cnt = 0;
            }
            i++;
        }
        max_count = max(max_count, cnt);

        return max_count;
        
    }
};