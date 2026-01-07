// 1975. Maximum Matrix Sum

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(1)

// Aprroach: Count negative numbers and track the smallest absolute value.  
// If the count of negative numbers is even, return the total sum of absolute values.
// If odd, subtract twice the smallest absolute value from the total sum.
// This ensures the maximum possible sum after flipping signs.

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int neg = 0;
        int minAbs = INT_MAX;

        for (auto& row : matrix) {
            for (int v : row) {
                if (v < 0) neg++;
                int av = abs(v);
                totalSum += av;
                minAbs = min(minAbs, av);
            }
        }

        return (neg % 2 == 0) ? totalSum : totalSum - 2LL * minAbs;
    }
};