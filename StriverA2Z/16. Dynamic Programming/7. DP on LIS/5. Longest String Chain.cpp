#include <bits/std.c++.h>
using namespace std;


// Time Complexity: O(n^2 * m) where n is the number of words and m is the average length of the words
// Space Complexity: O(n)

// Approach: Sort the words based on their lengths. Use dynamic programming to find the longest string chain. For each word, check all the previous words to see if they are predecessors of the current word. If they are, update the dp array accordingly. Finally, return the maximum value in the dp array as the answer.

class Solution {
private:
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }

    bool is_predecessor(string wordA, string wordB){
        int n = wordA.size();

        // check if wordA is predecessor of wordB
        if (wordB.size() != wordA.size() + 1) return false;
        
        // check for predecessor
        int i=0; int j=0; int extra = 0;

        while (i<n && j<n+1 && extra <= 1){
            if (wordA[i] == wordB[j]){
                i++; j++;
            }else{
                extra++;
                j++;
            }
        }
        if (extra > 1) return false;
        else return true;

    }
public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();

        sort(words.begin(), words.end(), comp);

        int ans = 1;

        vector<int> dp(n,1);  // length of longest sting chain

        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (is_predecessor(words[j], words[i])){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};


// Time Complexity: O(n * m^2) where n is the number of words and m is the average length of the words
// Space Complexity: O(n)

// Approach: Sort the words based on their lengths. Use a hash map to store the length of the longest chain ending at each word. For each word, generate all possible predecessors by removing one character at a time and check if they exist in the hash map. If they do, update the hash map for the current word. Finally, return the maximum value in the hash map as the answer.

class Solution {
private:
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();

        sort(words.begin(), words.end(), comp);

        // dp[word] = length of longest chain ending at this word
        unordered_map<string, int> dp;
        int ans = 1;


        for (int i=0; i<n; i++){
            string word = words[i];
            dp[word] = 1;

            // generate all possible predecessors by removing 1 char
            for (int j=0; j<word.size(); j++){
                string prev = word.substr(0,j) + word.substr(j+1);

                if (dp.count(prev)){
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};