#include <iostream>
# include <vector>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        for (int i=1; i<n; i++){
            if (largest < arr[i]){
                largest = arr[i];
            }
        }
        return largest;
    }
};

// Time - 0.33 sec