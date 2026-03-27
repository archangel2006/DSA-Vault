#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)


class Solution {
  public:
    int findMin(int n) {
        int cnt = 0;

        cnt += n / 10;
        n %= 10;

        cnt += n / 5;
        n %= 5;

        cnt += n / 2;
        n %= 2;

        cnt += n; // remaining 1s

        return cnt;
    }
};



class Solution {
  public:
    int findMin(int n) {
        
            int cnt = 0;
            int coins;
        
            if (n >= 10){
                coins = n/10;
                cnt += coins;
                n -= coins*10;
            }
            if (n >= 5){
                coins = n/5;
                cnt += coins;
                n -= coins*5;
            }
            if (n>=2){
                coins = n/2;
                cnt += coins;
                n -= coins*2;
            }
            cnt += n;
            
            return cnt;
        
    }
};