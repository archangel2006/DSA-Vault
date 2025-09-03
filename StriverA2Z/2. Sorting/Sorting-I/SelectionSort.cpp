#include <iostream>
#include <vector> 
#include <algorithm>  // for std::swap
using namespace std;

class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        int n= arr.size();
        for (int i=0; i<n-1; i++){
            int smallest_i = i;
            for (int j=i+1; j<n; j++){
                if (arr[j] < arr[smallest_i]){
                    smallest_i = j;
                }
            }
            swap(arr[smallest_i], arr[i]);
        }
    }
};

// Time : 0.03 sec


// COMPANIES

// Microsoft
// Medlife