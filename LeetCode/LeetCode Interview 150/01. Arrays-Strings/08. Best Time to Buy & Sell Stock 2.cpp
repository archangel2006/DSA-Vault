#include <bits/stdc++.h>
using namespace std;




// OPTIMIZED APPROACH


// Optimization: Instead of tracking valleys and peaks, we can simply add up all positive differences between consecutive days. This approach captures all profitable transactions without explicitly identifying buy and sell points.
// Algorithm: Greedy

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int totalProfit = 0; // stores total profit from all profitable trades

        // iterate through each consecutive day
        for (int i = 0; i < prices.size() - 1; i++) {
            int buy = prices[i];
            int sell = prices[i + 1];  

            // if there's profit, add it
            if (sell - buy > 0)
                totalProfit += sell - buy;
        }

        return totalProfit;
        
    }
};

// BRUTE FORCE APPROACH

// Algorithm: Valley-Peak Approach
// Find all local minima (valleys) and local maxima (peaks) in the price array. Buy at each valley and sell at the next peak to maximize profit.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution { 
public:
    int maxProfit(vector<int>& prices) {

        int totalProfit = 0; // stores total profit from all profitable trades
        int n = prices.size();
        int i = 0;

        while (i < n - 1) {
            // Find the next valley (local minimum)
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            int valley = prices[i];

            // Find the next peak (local maximum)
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            int peak = prices[i];

            // Add the profit from this transaction
            totalProfit += peak - valley;
        }

        return totalProfit;
        
    }
};