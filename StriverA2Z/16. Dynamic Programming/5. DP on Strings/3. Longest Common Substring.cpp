#include <bits/stdc++.h>
using namespace std;

// Memoization

// Time Complexity: O(N*M)
// Space Complexity: O(N*M) + O(N+M) [DP Array + Recursion Stack]

class Solution {
private:
    int ans = 0;

    int f(int i, int j, string &text1, string &text2, vector<vector<int>>& dp){

        // Base Case
        if (i<0 || j<0) return 0;

        // If already computed
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // If characters match, take diagonal
        if (text1[i] == text2[j]){
            dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);
            ans = max(ans, dp[i][j]);
            return dp[i][j];
        }

        // Otherwise RESET
        return dp[i][j] = 0;
        //return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));

    }
public:
    int longestCommonSubstring(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n, vector<int>(m,-1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f(i, j, text1, text2, dp);
            }
        }

        return ans;
        //return f(n-1, m-1, text1, text2, dp);
    }
};


// Tabulation

// Time Complexity: O(N*M)
// Space Complexity: O(N*M) [DP Array]

class Solution {
public:
    int longestCommonSubstring(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // dp[i][j] = LCS
        
        // 1. Base Case
        for (int i=0; i<n+1; i++){
            dp[i][0] = 0;
        }
        for (int i=0; i<m+1; i++){
            dp[0][i] = 0;
        }

        int ans = 0;
    
        // 2. Recursion
        for (int i=1; i<n+1; i++){
            for (int j=1; j<m+1; j++){

                // Character match - take diagonal
                if (text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }

                // Characters don't match - reset
                else{
                    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = 0;
                }
            }
        }

        return ans;

    }
};

/*

| Aspect       | LCS                | LCSubstring             |
| ------------ | ------------------ | ----------------------- |
| Continuity   | ❌                  | ✅                       |
| On mismatch  | max(left, up)      | **reset to 0**          |
| dp meaning   | best till prefixes | **ending exactly here** |
| Final answer | dp[n][m]           | **max over table**      |
| Memo call    | f(n-1,m-1)         | **all (i,j)**           |

*/