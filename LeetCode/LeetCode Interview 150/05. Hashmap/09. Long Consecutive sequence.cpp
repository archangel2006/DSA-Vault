#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }

        int l=0;
        set<int> s(nums.begin(), nums.end());

        if (s.empty()) return -1;
                
        int mn = *s.begin();
        int mx = *s.rbegin();
    
        int max_l = 0;

        for (int i=mn; i<mx+1;i++){
            if (s.find(i) != s.end()){
                l++;
            }else{
                max_l = max(l, max_l);
                l = 0;
            }

        }
        return max(max_l,l);
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int l = 0;
        set<int> s(nums.begin(), nums.end());

        int max_l = 0;
        int prev; 
        bool first = true;  // flag to check the first number

        for (int num : s) {  // iterate in sorted order
            if (first) {
                l = 1;       // first number starts a sequence
                first = false;
            } else if (num == prev + 1) {
                l++;         // consecutive number
            } else {
                l = 1;       // not consecutive, start new sequence
            }
            max_l = max(max_l, l);
            prev = num;      // update previous number
        }

        return max_l;
    }
};
