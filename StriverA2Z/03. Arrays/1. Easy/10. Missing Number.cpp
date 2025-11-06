#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());

        for (int i=1; i<=n;i++){
            if (s.find(i) == s.end()){
                return i;
            }
        }
        return 0;
        
    }
};