
#include <iostream>
using namespace std;

class Solution {
  public:
    bool isEven(int n) {
        //3=11 ; 7=111; 9= 1001; 11=1011; 13=1101; 15=1111 
        /// 2=10; 4=100; 6=110; 44 = 101100 : all end with 0
        
        return ((n&1) == 0); // 0|1 = 0
        
    }
};