#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q; // traversal queue
        
        int initial = image[sr][sc];

        // Finding and marking imge[sr][sc]
        q.push({sr,sc});
        image[sr][sc]=color;
        

        while(!q.empty()){ 
            int i = q.front().first; 
            int j = q.front().second;

            q.pop();

            // changing color of neighboring cells

            int add_row[] = {-1,0,1,0};
            int add_col[] = {0,1,0,-1};

            for (int add=0; add<4; add++){  //up,down,right,left
                int new_row = i + add_row[add];
                int new_col = j + add_col[add];

                // if in bounds, not colored alr & same color as initial
                if (new_row>=0 && new_row<n && new_col>=0 &&new_col<m && 
                image[new_row][new_col]!=color && image[new_row][new_col]==initial){
                    q.push({new_row, new_col});
                    image[new_row][new_col] = color;
                }
            }
        }

        return image;
        
    }
};