#include <iostream>
using namespace std;

// User function Template for C++

class Solution {
  private:
    int XOR_upto_n(int n){
        if (n%4==0) return n;
        else if(n%4==1) return 1;
        else if (n%4==2) return n+1;
        else return 0;
    }
  public:
    int findXOR(int l, int r) {
        return (XOR_upto_n(r)^XOR_upto_n(l-1));
        
    }
};


/*
1^2 = 3;  remainder = 2; ans = n+1
1^2^3 = 0; remainder = 3; ans = 0
1^2^3^4 = 4;  remainder = 0; ans = n
1^2^3^4^5 = 1; remainder = 
1^2^3^4^5^6 = 7;
*/