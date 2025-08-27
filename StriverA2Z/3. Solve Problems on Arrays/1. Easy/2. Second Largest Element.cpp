#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l1 = arr[0];
        int l2 = -1;
        
        for (int i=1; i<n;i++){
            if (arr[i]>l1){
            l1=arr[i];
            }
        }
        
        for (int j=0; j<n; j++){
            if (arr[j]>l2 && arr[j]<l1){
                l2 = arr[j];
            }
        }
        
        
        return l2;
        
    }
};

// Time : 0.26 sec