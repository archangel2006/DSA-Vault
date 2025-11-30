#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int max_cnt=0;
        int n = nums.size();
        for (int num : nums){
            if (num == 1){
                cnt++;
                max_cnt = max(max_cnt, cnt);
            }else{
                //max_cnt = max(max_cnt, cnt);
                cnt = 0;
            }
        }
        //max_cnt = max(max_cnt, cnt);

        return max_cnt;
        
    }
};