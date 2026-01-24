#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        
        // 1. Base Case
        for (int i=0; i<n+1; i++){
            dp[i][0] = i;
        }
        for (int i=0; i<m+1; i++){
            dp[0][i] = i;
        }

        // 2. Recursion
        for (int i=1; i<n+1; i++){
            for (int j=1; j<m+1; j++){

                // Character match - take diagonal
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }

                // Characters don't match - skip one side
                else{
                    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = 1 + min({
                        dp[i-1][j],    // delete
                        dp[i][j-1],    // insert
                        dp[i-1][j-1]   // replace
                    });
                }
            }
        }

        return dp[n][m];
    }
};