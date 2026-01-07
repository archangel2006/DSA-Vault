// 66. Plus One

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach: Start from the last digit and add one. If there is a carry, propagate it to the left.
// If after processing all digits there is still a carry, insert it at the beginning of the vector.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n=digits.size();
        int carry = 1;

        for (int i=n-1; i>=0; i--){

            int sum = digits[i] + carry;  // add carry digit
            digits[i] = sum%10; // store last digit
            carry = sum/10;  // update carry

            if (carry == 0) break;
        }

        if (carry) digits.insert(digits.begin(), carry);

        return digits;
    }
};