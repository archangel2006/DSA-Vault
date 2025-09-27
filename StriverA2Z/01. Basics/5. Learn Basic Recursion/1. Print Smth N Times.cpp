#include <iostream>

#include <vector>
using namespace std;


class Solution {
  public:
    void printNTimes(char c,int N) {
        if (N==0){
            return;
        }else{
            cout << "c ";
            printNTimes(c,N-1);
        }
    }
};
