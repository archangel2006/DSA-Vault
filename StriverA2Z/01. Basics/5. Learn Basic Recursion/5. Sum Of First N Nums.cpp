#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
  public:
    int sumOfSeries(int n) {
        if (n==0){
            return 0;
        }else{
            return pow(n, 3) + sumOfSeries(n-1);
        }
        
    }
};

//Time : 0.01s