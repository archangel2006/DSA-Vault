#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Time: 15ms

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;

        for (int num : nums){
            if (num > 0){
                positive.push_back(num);
            }else{
                negative.push_back(num);
            }
        }
        vector<int> result;
        for (int i=0; i<(n/2); i++){
            result.push_back(positive[i]);
            result.push_back(negative[i]);

        }
        return result;
    }
};

// Time:8sec

// Reduces space
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0;
        int j = 1;

        for (int num : nums){
            if (num > 0){
                result[i] = num;
                i+=2;
            }else{
                result[j] = num;
                j+=2;
            }
        }
        return result;
    }
};