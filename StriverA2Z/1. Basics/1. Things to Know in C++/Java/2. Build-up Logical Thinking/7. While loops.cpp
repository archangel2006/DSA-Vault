#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void calculateMultiples(int n) {
        int k=10;
        while (k>0){
            cout<<k*n<<" ";
            k--;
        }
    }
};

// Time: 0.01