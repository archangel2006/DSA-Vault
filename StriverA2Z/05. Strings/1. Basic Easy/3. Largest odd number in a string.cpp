#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   
using namespace std;


class Solution {
public:
    string largestOddNumber(string num) {
        reverse(num.begin(), num.end());

        string ans="";
        for (int i=0; i<num.size(); i++){
            if (num[i]%2!=0){
                ans = num.substr(i);
                reverse(ans.begin(),ans.end());
                break; 
            }
        }
        return ans;
    }
};