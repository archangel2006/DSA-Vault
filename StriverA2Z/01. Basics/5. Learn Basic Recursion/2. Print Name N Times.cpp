#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void printGfg(int N) {
        if (N==0){
            return;
        }else{
            cout << "GFG ";
            printGfg(N-1);
        }
    }
};

// Time : 0.02s


