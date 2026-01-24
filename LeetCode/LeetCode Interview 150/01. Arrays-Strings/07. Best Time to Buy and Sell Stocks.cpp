#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuy = INT_MAX;
        

        for (int price : prices){
            minBuy = min(minBuy, price);  // cheapest price before today
            maxProfit = max(maxProfit, price - minBuy);
        }

        return maxProfit;


        
    }
};