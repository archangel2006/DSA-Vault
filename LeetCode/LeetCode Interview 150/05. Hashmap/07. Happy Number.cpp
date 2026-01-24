#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(log n)

class Solution {
public:
    bool isHappy(int n) {

        if (n==1) return true;
        //if (n<10) return false;

        unordered_set<int> S;

        while (n != 1){
            if (n == 1) return true;

            if (S.find(n)!=S.end()) return false;
            S.insert(n);

            int num = n;

            int sum=0;
            while (num != 0) {
                int digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }

            n = sum;
        }

        return true;
    }
};