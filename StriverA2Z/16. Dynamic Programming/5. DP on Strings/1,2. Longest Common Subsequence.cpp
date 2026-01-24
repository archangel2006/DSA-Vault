#include <bits/stdc++.h>
using namespace std;

// Memoization

// Time Complexity: O(N*M)
// Space Complexity: O(N*M) + O(N+M) [DP Array + Recursion Stack]

// 42ms
class Solution {
private:
    int f(int i, int j, string &text1, string &text2, vector<vector<int>>& dp){

        // Base Case
        if (i<0 || j<0) return 0;

        // If already computed
        if (dp[i][j] != -1){
            return dp[i][j];
        }

        // If characters match, take diagonal
        if (text1[i] == text2[j]){
            return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);
        }

        // Otherwise skip one character from either string
        return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp));

    }
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n, vector<int>(m,-1));
        
        return f(n-1, m-1, text1, text2, dp);


    }
};


// Tabulation

// Time Complexity: O(N*M)
// Space Complexity: O(N*M) [DP Array]

// 25ms
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

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

        // 2. Recursion
        for (int i=1; i<n+1; i++){
            for (int j=1; j<m+1; j++){

                // Character match - take diagonal
                if (text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                // Characters don't match - skip one side
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];

    }
};