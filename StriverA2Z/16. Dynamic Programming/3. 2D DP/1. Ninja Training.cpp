#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// RECURSION

// 9/1100 test cases passed

//Time Complexity: O(3^N) where N is the number of days
//Space Complexity: O(N) for the recursion stack

class Solution {
    
  private:
    int F(int day, int prev_task, vector<vector<int>>& arr){
        
        int max_points = 0;

        //Base Case
        if (day==0){
            
            // 1st day when no prev task has been performed, we chose the maximum points that can be achieved
            for (int i=0; i<3; i++){ 
                max_points = max(max_points, arr[0][i]);
            }
            return max_points; //return points for the 1st day call
        }
        
        
        // Recursion
        for (int i=0; i<=2; i++){
            if (i!=prev_task){
                int point = arr[day][i] + F(day-1,i,arr);
                max_points = max(max_points, point);
            }
            
        }
        
        
        return max_points;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int days = arr.size();
        int tasks = 3;
        
        vector<vector<int>> dp(days,vector<int>(3,-1));
        
        return F(days-1,3, arr);
        
    }
};


// ERRORS WITH THE BASE CASE:
//Base Case
        if (day==0){
            
            // 1st day when no prev task has been performed, we chose the maximum points that can be achieved
            for (int i=0; i<3; i++){ 
                // ADD THIS CONDITION 
                if (i!=prev_task)
                // CAUSE EVEN THOUGH IT IS THE 1ST DAY, prev_task CAN BE 0,1 OR 2 BECAUSE WE'RE MOVING IN REVERSE DIRECTION
                max_points = max(max_points, arr[0][i]);
            }
            return max_points; //return points for the 1st day call
        }
// HERE WHAT



// MEMOIZATION

// Time Complexity: O(N*4*3) ~ O(N) where N is the number of days
// Space Complexity: O(N*4) + O(N) ~ O(N)

class Solution {
    
  private:
    int F(int day, int prev_task, vector<vector<int>>& arr, vector<vector<int>>& dp){

        int max_points = 0;
        
        //Base Case
        if (day==0){    //1st day
            
            // 1st day when no prev task has been performed, we chose the maximum points that can be achieved
            for (int i=0; i<3; i++){ // chose the max task of 1st day
                if (i!=prev_task)   // recursion backward, so we need to make sure day+1 task is not repeated on day
                max_points = max(max_points, arr[0][i]);
            }
            return dp[day][prev_task] = max_points; //return points for the 1st day call
        }
        
        if (dp[day][prev_task] !=-1) return dp[day][prev_task];
        // Recursion
        for (int i=0; i<=2; i++){
            if (i!=prev_task){
                int point = arr[day][i] + F(day-1,i,arr, dp);
                max_points = max(max_points, point);
            }
            
        }
        return dp[day][prev_task] = max_points;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int days = arr.size();
        int tasks = 3;
        
        vector<vector<int>> dp(days,vector<int>(4,-1)); // arr:0...n-1 values // 4 possibilties {0,1,2,3}
        
        return F(days-1,3, arr, dp); 
        
    }
};

// TABULATION

// Time Complexity: O(N*4*3) ~ O(N) where N is the number of days
// Space Complexity: O(N*4) ~ O(N)

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        
        int days = arr.size();
        int tasks = 3;
        
        //dp[day][lastTask] = maximum points till this day, if yesterday we did `lastTask`

        vector<vector<int>> dp(days,vector<int>(4,-1)); // arr:0...n-1 values // 4 possibilties {0,1,2,3}
        
        // Base Case
        
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});
        
        
        // Loops 
        
        for (int day=1; day<days; day++){
            for (int last_task = 0; last_task<4; last_task++){
                dp[day][last_task] = 0;
                for (int task=0; task<3; task++){
                    if (task!= last_task){
                        int point = arr[day][task] + dp[day-1][task];
                        dp[day][last_task] = max(dp[day][last_task], point);
                    }
                }
            }
        }
        return dp[days-1][3];
        
    }
};
