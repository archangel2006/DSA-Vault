
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i= 0;
        int j= n;
        int k =0;
        vector<int>result(2*n);

        while (k+1<=2*n){
            result[k] = nums[i];
            result[k+1] = nums[j];
            i++;
            j++;
            k+=2;
        }

        return result;
        
    }
};