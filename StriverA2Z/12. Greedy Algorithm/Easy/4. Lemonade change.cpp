#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();

        int five = 0, ten = 0, twenty = 0;

        for (int bill : bills){
            if (bill == 5) five++;
            else if (bill == 10){
                if (five>0){
                    ten++;
                    five--;
                }else{
                    return false;
                }
            }
            else if (bill == 20){
                if (five>0){
                    if (ten>0){
                        ten--;
                        five--;
                        twenty++;
                    }
                    else if (five>=3){
                        five-=3;
                        twenty++;
                    }else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};