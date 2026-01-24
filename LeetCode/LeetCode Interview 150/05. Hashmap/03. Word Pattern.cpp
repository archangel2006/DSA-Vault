#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n) where n is the length of pattern and s
// Space Complexity: O(k) where k is the number of unique characters in pattern and words

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map = {};

        unordered_set<string>word_set;
        vector<string> words;
        istringstream iss(s);
        string word;

        // The >> operator extracts words separated by whitespace
        while (iss >> word) {
            words.push_back(word);
            word_set.insert(word);
        }

        if (pattern.size() != words.size()) return false;

        for (int i=0; i<pattern.size(); i++){
            if (map.find(pattern[i]) != map.end()){
            // if (map.contains(pattern[i])){
                if (map[pattern[i]] != words[i]) return false;
            }
            map[pattern[i]] = words[i];
        }

        if (word_set.size() != map.size()) return false;

        return true;    
    }
};