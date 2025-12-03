#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q; // traversal queue
        vector<vector<int>>vis(n, vector<int>(m, 0)); // new matrix
        

        // Finding and marking rotten oranges
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 2){ // rotten
                    q.push({{i,j},0}); // rotten oranges at time 0
                    vis[i][j] = 2;  // mark rotten oranges in new matrix
                }else{
                    vis[i][j] = 0; // mark other cells as 0
                }
            }
        }

        int time = 0;

        // pop initial rotten oranges
        while(!q.empty()){ 
            int i = q.front().first.first; 
            int j = q.front().first.second;
            int curr_time = q.front().second; //time at which this orange rots

            q.pop();
            time = max(time,curr_time);


            // rotting neighboring fresh oranges

            int add_row[] = {-1,0,1,0};
            int add_col[] = {0,1,0,-1};

            for (int add=0; add<4; add++){  //up,down,right,left
                int new_row = i + add_row[add];
                int new_col = j + add_col[add];

                // if in bounds, not rotted alr & fresh
                if (new_row>=0 && new_row<n && new_col>=0 &&new_col<m && 
                vis[new_row][new_col]!=2 && grid[new_row][new_col]==1){
                    q.push({{new_row, new_col},curr_time+1});
                    vis[new_row][new_col] = 2;
                }
            }
        }

        // check if any fresh oranges left at the end

         for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};