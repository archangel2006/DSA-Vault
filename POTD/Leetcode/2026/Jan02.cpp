// 961. N-Repeated Element in Size 2N Array

#include<bits/stdc++.h>
using namespace std;


// Timre Complexity: O(N)
// Space Complexity: O(N)

// Approach: Using HashMap to store frequency of each element and using HashSet to store unique elements.
// Then, we find the element whose frequency is equal to size of unique elements - 1.
 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        unordered_map<int,int> freq;
        unordered_set<int>unique;

        for (int num:nums){
            freq[num]++;
            unique.insert(num);
        }
        int n = unique.size();
        for(auto& [key,value] : freq){
            if (value == n-1) return key;
        }
        
        return -1;
        
    }
};