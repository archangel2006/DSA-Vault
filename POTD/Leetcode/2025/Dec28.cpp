// 1351. Count Negative Numbers in a Sorted Matrix

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH

// Time Complexity: O(m*n)
// Space Complexity: O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int cnt=0;
        
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (grid[i][j] < 0) cnt++;
            }
        }
        
        return cnt;
    }
};

// OPTIMIZED APPROACH

// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        /*
        4   3  2 -1
        3   2  1 -1
        1   1 -1 -2
        -1 -1 -2 -3
        */

        int m = grid.size(); int n = grid[0].size();

        int i=0; int j=n-1; // top-right

        int cnt=0;

        while (i<m && j>=0){
            if (grid[i][j] < 0){ // negative
                cnt += m-i;   //if current is negative, all rows below it are negative
                j -= 1; // move left
            }
            else{
                i+=1; // if current is negative move down a row
            }
        }

        return cnt++;
    }
};