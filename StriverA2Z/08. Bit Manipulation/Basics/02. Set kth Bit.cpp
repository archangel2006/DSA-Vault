#include <iostream>
using namespace std;

class Solution {
  public:
    int setKthBit(int n, int k) {
        
        // shift 1 to kth place
        int shift = 1<<k;
        
        // 0|1 , 1|1 sets 1
        int ans = shift | n;
        
        return ans;
    }
};
