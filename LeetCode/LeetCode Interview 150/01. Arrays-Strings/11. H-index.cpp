#include <bits/stdc++.h>
using namespace std;


// OPTIMIZED APPROACH
// Algorithm: Counting Sort Approach

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int hIndex(vector<int>& citations) {

        // cites[h] = number of papers with ≥ h citations

        // citation index : number of papers
        unordered_map<int,int> cites={};

        // try all possible h values (0 to n)
        for (int h = 0; h <= n; h++) {
            // count papers with citations >= h
            for (int i = 0; i < n; i++) {
                if (citations[i] >= h) {
                    cites[h]++;
                }
            }
        }


        int h_index = 0;

// {0 : 5, 1 : 4, 2 : 3, 3 : 3, 4 : 2, 5 : 2}

        // choose the maximum valid h
        for (auto& [key,value] : cites){
            if (value>=key){
                h_index = max(h_index, key);
            }        
        }

        return h_index;
    }
};