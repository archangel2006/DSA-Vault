#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


// 43/83 test cases passed

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()){
            return 0;
        }

        int l=0;
        set<int> s(nums.begin(), nums.end());

        int mn = *s.begin();
        int mx = *s.rbegin();

        for (int i=mn; i<mx+1;i++){
            if (s.find(i) != s.end()){
                l++;
            }else{
                break;
            }

        }
        return l;
    }
};

// 70/83 test cases passed

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()){
            return 0;
        }

        int l=0;
        set<int> s(nums.begin(), nums.end());

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


// TRY AGAIN

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) {  // start of sequence
                int current = num;
                int streak = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }

        return longest;
    }
};
