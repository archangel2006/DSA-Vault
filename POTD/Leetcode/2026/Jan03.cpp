// 1411. Number of Ways to Paint N × 3 Grid

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

// Approach: Dynamic Programming

class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        
        // dpA: ways where a row has 3 different colors (ABC)
        // dpB: ways where first and third colors are same (ABA)
        long long dpA = 6, dpB = 6;  // base case for n = 1
        
        for (int i = 2; i <= n; i++) {
            // Transition from previous row
            long long newA = (2 * dpA + 2 * dpB) % MOD;
            long long newB = (2 * dpA + 3 * dpB) % MOD;
            
            dpA = newA;
            dpB = newB;
        }
        
        // Total ways = type A + type B
        return (dpA + dpB) % MOD;
    }
};

/*
-  We categorize the ways to paint each row into two types:
    1. Type A (dpA): All three colors are different (e.g., RGB, RBG, etc.)
    2. Type B (dpB): First and third colors are the same (e.g., RGR, BGB, etc.)
- For each new row added, we can derive the number of ways based on the previous rows:
    - From a Type A row, we can form 2 Type A rows and 2 Type B rows.
    - From a Type B row, we can form 2 Type A rows and 3 Type B rows.        
- We use these transitions to build our solution iteratively.
- Finally, the total number of ways to paint the grid is the sum of both types.

*/