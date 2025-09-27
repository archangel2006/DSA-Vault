#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void printNos(int N) {
        if (N==0){
            return;
        }else{
            cout << N;
            cout << ' ';
            printNos(N-1);
        }
        
    }
};

// Time : 0.02s