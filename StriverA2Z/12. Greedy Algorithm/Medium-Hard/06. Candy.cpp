#include <bits/stdc++.h>
using namespace std;


// 18 / 50 testcases passed

// Time Complexity: O(n)
// Space Complexity: O(n)  

//Approach: directly comparing the ratings of children and assigning candies accordingly.
class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> candies(n,1);

        for (int i=0; i<n-1; i++){
            if (ratings[i] > ratings[i+1]) candies[i]++;
            else if (ratings[i] < ratings[i+1]) candies[i+1]++;
        }

        int ans = 0;

        for (int num : candies){
            ans += num; 
        }
        return ans;
    }
};