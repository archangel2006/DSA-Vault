#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 1010/1120 test cases passed
//expected time: <2.12sec

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int max_sum=0;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                vector<int> subarray(arr.begin()+i, arr.begin()+j+1);
                sort(subarray.begin(), subarray.end());
                int sum = subarray[0] + subarray[1];
                max_sum = max(sum, max_sum);
            }
        }
        return max_sum;
        
    }
};

//OPTIMIZED

// SLidig Window