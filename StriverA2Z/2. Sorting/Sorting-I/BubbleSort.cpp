#include <iostream>
#include <vector> 
#include <algorithm>  // for std::swap
using namespace std;

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        
        int n = arr.size();
        
        for (int i=0; i<n-1; i++){
            for (int j=0; j<n-i-1; j++){
                if (arr[j]>arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};

// Time Taken : 0.07 sec



// COMPANIES :

// Microsoft
// Wipro
// SAP Labs
// Cisco
// Nagarro
// redBus
// Accenture
// Huawei