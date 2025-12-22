#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> all;
        vector<int> ans;
        for (int num : nums){
            all.insert(num);   
        }

        for (int i=1; i<=nums.size(); i++){
            if (all.find(i)==all.end()) ans.push_back(i);
        }

        return ans;
    }
};