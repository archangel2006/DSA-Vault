#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void printNos(int n) {
        if (n==0){
            return;
        }else{
            printNos(n-1);
            cout <<' ';
            cout << n;
            
        }
    }
};

// Time : 0.02s