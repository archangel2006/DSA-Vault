#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


// 34ms
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> freq;
        int duplicate=-1;
        int missing=-1;

        for (int num : nums) {
            freq[num]++;   
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 2)
                duplicate = i;
            else if (freq[i] == 0)
                missing = i;
        }
        
        return {duplicate, missing};
        
    }
};

// 92ms TT
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>final;
        set<int>curr;
        int rep;

        for (int i=1; i<=nums.size(); i++){
            final.insert(i);
        }
        for (int num:nums){
            if (curr.find(num)!=curr.end()) rep = num;
            curr.insert(num);
            
        }
        set<int> reqd; //= final-curr;
        set_difference(final.begin(), final.end(), curr.begin(), curr.end(), inserter(reqd, reqd.begin()));
        int reqd_num = *reqd.begin();

        vector<int>ans={rep,reqd_num};

        return ans;       
    }
};