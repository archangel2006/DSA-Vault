#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        
        int left_capacity = capacity;
        int i=0;
        double max_val = 0;
        
        while (i<n && left_capacity > 0){
            
            if (left_capacity > wt[i]){
                
                left_capacity -= wt[i];
                max_val += val[i];
                
            }else{
                //float fraction = left_capacity/wt[i];
                double fraction = (double)left_capacity / wt[i];
                max_val += fraction*val[i];
                break;
            }
            i++;
        }
        
        return max_val;
        
    }
};


// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        
        vector<pair<double, int>> items;
        
        for (int i=0; i<n; i++){
            items.push_back({(double)val[i]/wt[i], i});
        }
        sort(items.begin(), items.end(), greater<>());

        int left_capacity = capacity;
        int i=0;
        double max_val = 0.0;
        
        while (i<n && left_capacity > 0){
            int idx = items[i].second;
            if (left_capacity > wt[idx]){
                
                left_capacity -= wt[idx];
                max_val += val[idx];
                
            }else{
            
                double fraction = (double)left_capacity / wt[idx];
                max_val += fraction*val[idx];
                break;
            }
            i++;
        }
        
        return max_val;
        
    }
};
