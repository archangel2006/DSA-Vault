#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// NAIVE  APPROACH
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        // The first argument (arr) is a pointer to the beginning of the range to be sorted.
        // The second argument (arr + n) is a pointer to one element past the end of the range to be sorted.

        vector<int>ans(n,0);
        ans[0] = 0;

        int i=1;

        while (i<n){
            if (nums[i]!=nums[i-1]){
                ans[i] = ans[i-1] + 1;
            }
            else{
                ans[i] = ans[i-1];
            }
            i++;
        }

        return ans;
        
    }
};

// MAPPING

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int>sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int,int>rank; // {number : original rank}

        // compute first occurrence index (this gives count of smaller numbers)

        for (int i=0; i<n; i++){
            if (rank.find(sorted[i]) == rank.end()){  // ensures only the first occurrence of a duplicate gets stored.
                rank[sorted[i]] = i;
            }
        }

        vector<int>ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = rank[nums[i]];
        }
        
        return ans;
        
    }
};

// SORTING WITH INDEX TRACKING

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

   
        
        vector<pair<int,int>> arr;
        
        for(int i=0; i<n; i++){
            arr.push_back({nums[i], i}); // value + original index
        }

        sort(arr.begin(), arr.end()); // sorts by value automatically

        vector<int>ans(n);
        ans[arr[0].second] = 0; // smallest number has 0 smaller

        int i=1;

        while (i<n){
            if (arr[i].first!=arr[i-1].first){
                ans[arr[i].second] = i;
            }
            else{
                ans[arr[i].second] = ans[arr[i-1].second];
            }
            i++;
        }

        return ans;
        
    }
};