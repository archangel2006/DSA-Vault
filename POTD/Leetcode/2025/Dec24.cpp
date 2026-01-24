// 3074. Apple Redistribution into Boxes

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n) due to sorting the capacity array
// Space Complexity: O(1)

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (auto cnt : apple){
            total+=cnt;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int min_boxes = 0;

        for (int x : capacity){
            if (total>0){
                total-=x;
                min_boxes++;
            }
            else break;
        }
        return min_boxes;
    }
};