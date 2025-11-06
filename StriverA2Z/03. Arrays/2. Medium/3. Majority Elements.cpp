#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;




class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq={};
        for (int num: nums){
            freq[num] += 1;
        }
        int maxFreq = 0;
        int element = -1;

        /*
        for (auto& [key,value] : freq){
            if (value > maxFreq){
                maxFreq = value;
                element = key;
            }
        */
        
        for (const pair<int,int>& p : freq){
            if (p.second > maxFreq){
                maxFreq = p.second;
                element = p.first;
            }
        }
        
        return element;
    }
};