#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(N*M)
// Space Complexity: O(N*M) [DP Array]

class Solution {
private:
    int LCS(string text1, string text2) {

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
public:
    int minDistance(string word1, string word2) {
        
        int insertions = word1.size() - LCS(word1, word2);
        int deletions = word2.size() - LCS(word1, word2);

        return insertions + deletions;
    }
};