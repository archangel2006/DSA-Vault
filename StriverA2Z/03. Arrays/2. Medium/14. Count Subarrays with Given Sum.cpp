#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BRUTE FORCE  Time:2466ms
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();

        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += nums[j];
                if (sum == k){
                    cnt++;
                }
                
                
            }
        }
        return cnt;
        
    }
};

// OPTIMIZED - Prefix Sum / HAshmap

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int running_sum = 0;
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1;  // base case

        for (int num : nums) {
            running_sum += num;
            if (sumFreq.find(running_sum - k) != sumFreq.end()) {
                count += sumFreq[running_sum - k];
            }
            sumFreq[running_sum]++;
        }

        return count;
    }
};
