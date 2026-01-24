// 3075. Maximize Happiness of Selected Children

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());  // O(n log n)
        int picks = INT_MAX;
        for (int num : happiness){ // O(n)
            if (num < picks) picks = num; 
        }

        long long total = 0;

        for (int i=0; i<k; i++){ // O(n)

            int add = happiness[i] - i; 
            if (add>=0){
                total+=add;
            }
            else break;  
        }

        return total;
    }
};