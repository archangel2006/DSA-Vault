#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// 38 / 58 testcases passed

class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = goal.size();

        if (n!=s.size()) return false;

        int j = 0;
        char start = goal[0];
        size_t i = s.find(start);

        while (j<n){
            if (i<n){
                if(s[i] != goal[j]){
                    return false;
                }
            }else if (i == s.size()) i=0;
            i++;
            j++;

        }
        return true;        
    }
};