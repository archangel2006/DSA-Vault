#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq={};

        for (int num : nums){
            freq[num]++;
        }

        int maxFreq = 0;
        int element = -1;

        for (auto& [key,value] : freq){
            if (value>maxFreq){
                maxFreq = value;
                element = key;
            }
        }

        return element;
    }
};