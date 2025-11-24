#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// Time Complexity: O(nlogn) sorting
// Space Complexity : O(n) for extra arrays

class Solution {
public:
    bool isAnagram(string s, string t) {

        int sn = s.size();
        int tn = t.size();

        if (sn!=tn) return false;

        vector<char> svec(sn);
        vector<char> tvec(tn);

        for (int i=0; i<sn; i++){
            svec[i] = s[i];
            tvec[i] = t[i];
        }

        sort(svec.begin(), svec.end());
        sort(tvec.begin(), tvec.end());

        return (svec == tvec);
    }
};