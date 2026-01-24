#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(m + n) where m is the length of ransomNote and n is the length of magazine
// Space Complexity: O(k) where k is the number of unique characters in magazine

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int>freq={}; // char : freq
        for (char c : magazine){
            freq[c]++;
        }

        unordered_set<char> chars;
        for (char c : ransomNote){
            freq[c]--;
            chars.insert(c);
        }

        for (auto& [key, value] : freq){
            if (value<0 && chars.find(key)!=chars.end()) return false;
        }
        return true;
    }
};