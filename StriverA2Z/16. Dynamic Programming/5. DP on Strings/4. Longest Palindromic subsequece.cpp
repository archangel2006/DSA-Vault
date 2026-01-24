#include <bits/stdc++.h>
using namespace std;

// Tabulation

// Time Complexity: O(N*N)
// Space Complexity: O(N*N) [DP Array]

// 88ms
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        
        // Base Case
        for (int i=0; i<n+1; i++){
            dp[0][i] = 0;
            dp[i][0] = 0;
        }

        // Recursion 
        for (int i=1; i<n+1; i++){
            for (int j=1; j<n+1; j++){
                
                // Character match
                if (s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                // Character doesn't match
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};