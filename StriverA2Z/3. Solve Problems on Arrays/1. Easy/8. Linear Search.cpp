#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        // code here
        int low = 0;
        int high = arr.size() - 1;
        
        while (low<=high){
            int mid = (low+high)/2;
            
            if (arr[mid] == k){
                return true;
            }else if (k<arr[mid]){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};

// Time : 0.1 sec