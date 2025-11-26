#include <iostream>
using namespace std;

/*
int n 
1 = 1
2 = 10
4 = 100    
8 = 1000    
16 = 10000
32 = 100000

- each power of 2 contains exactly one bit set

int n-1
0 = 0
1 = 1
3 = 11
7 = 111
15 = 1111
31 = 11111

n&(n-1)

1 & 0 = 0
10 & 01 = 0
100 & 011 = 0
1000 & 0111 = 0
10000 & 01111 = 0

*/



class Solution {
public:
    bool isPowerOfTwo(int n) {

        return n>0 && ((n&(n-1)) == 0);
    }  
    
};


		
		