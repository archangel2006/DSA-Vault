#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time: 0.07sec

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int prev_max = arr[n-1];
        vector<int> output;
        
        for (int i= n-1; i>=0; i--){
            if (arr[i] >= prev_max){
                prev_max = arr[i];
                output.push_back(arr[i]);
            }
        }
        //output.reverse();
        reverse(output.begin(), output.end());
        return output;
    }
};