#include <iostream>
#include <vector>
using namespace std;    

class Solution {
  public:
    int factorial(int n) {
        if (n==0 || n==1){
            return 1;
        }else{
            return n*factorial(n-1);
        }
        
    }
};

// Time: 0.02s