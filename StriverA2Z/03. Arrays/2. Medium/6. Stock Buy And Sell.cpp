#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// 200/212 test case passed

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int i = 0;
        int j=i+1;


        while (i<n && i<j){ //Fragile Condition
            j = i+1;
            for (j=i; j<n; j++){
                if (prices[j] > prices[i]){
                    profit = max(profit, prices[j] - prices[i]);
                }
            }
            i++;
        }
        return profit;

        
    }
};


// Nested Loop
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                profit = max(profit, prices[j] - prices[i]);
            }
        }

        return profit;

        
    }
};


// OPTIMIZED

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices){
            minPrice = min(minPrice, price); // buying at minimum price
            maxProfit = max(maxProfit, price - minPrice); // finding maximum profit by subtracting minPrice
        }

        return maxProfit;
        
    }
};

/*
1️⃣ Start with the problem
“We’re trying to find the maximum profit from buying and selling a stock once. We have an array of stock prices, where each element represents the price on that day. We want to buy on one day and sell on a later day to maximize profit.”

2️⃣ Explain the naive (nested loop) approach
“A simple way to do this is:
For each day, consider buying on that day.
Then look at all future days to see which day would give the best selling price.
Keep track of the maximum profit seen so far.
This works logically, but it’s slow because for every day, we check all future days — so it’s O(n²), which is too slow for large arrays.”

3️⃣ Explain the optimized single-pass approach
“We can make it much faster using a single pass:
We keep track of the lowest price seen so far as we go through the array.
For each day, we calculate the profit if we sell today after buying at the lowest price.
If this profit is bigger than the current max profit, we update it.
At the end, the max profit is the answer.
This works because by always remembering the cheapest buy so far, we are implicitly considering all buy-sell pairs without checking each one individually.”

4️⃣ Optional analogy
“Think of it like walking through a valley of stock prices:
We’re always keeping track of the lowest point we’ve seen.
Every new price we see, we ask: ‘If I had bought at the lowest point and sold today, how much profit would I make?’
We update our maximum profit if it’s better.
So we only need one pass, instead of checking every possible pair of buy and sell days.”

5️⃣ Highlight the main difference
“So the difference between my initial approach and the optimized one is:
Logic is the same: both find the best buy and sell combination.
Implementation is different: the single-pass approach doesn’t use nested loops, it just keeps track of the minimum price and maximum profit while scanning the array once — making it much faster.”*/