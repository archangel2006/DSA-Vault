#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For M_PI
using namespace std;

class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        
        switch(choice){
            case 1:
                return M_PI*arr[0]*arr[0];
                
            
            case 2:
                return arr[0]*arr[1];
        }
        
    }
};

// Time : 0.01