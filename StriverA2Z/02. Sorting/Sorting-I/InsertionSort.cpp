#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i=1; i<n; i++){
            int curr = arr[i];
            int pointer = i-1;
            while (pointer>=0 && pointer<n){
                if (curr < arr[pointer]){
                    arr[pointer+1] = arr[pointer];
                    pointer--;
                }else{
                    break;
                }
            }
            arr[pointer+1] = curr;
        }
    }
};

// Time : 0.03 sec



// COMPANIES

// Microsoft
// MAQ Software
// Juniper Networks
// Cisco
// Accenture
// Dell
// Veritas
// Grofers