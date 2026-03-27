#include <bits/stdc++.h>
using namespace std;


// 13 / 25 testcases passed

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int total = 0;

        for (int cookie : s){
            total+= cookie;
        }

        sort(g.begin(), g.end());

        int i=0, cnt=0;

        while (total>0 && i<g.size()){
            total -= g[i];
            if (total>=0) cnt++;
            i++;
        }
        
        return cnt;
    }
};

// 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0, j=0, cnt=0;

        while (j<s.size() && i<g.size()){
            int cookie = s[j];
            int left = cookie - g[i];

            if (left < 0){ // greed not satisfied
                j++;
            }else{
                cnt++;
                i++;
                j++;
            }
        }
        
        return cnt;
    }
};