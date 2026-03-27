#include <iostream>
#include <vector>
using namespace std;


//(38 / 39 testcases passed)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // int prev = arr[0];
        // int curr = arr[i];
        // arr[i] = prev

        int prev = nums[0];
        while (k>0){
            for (int i=1; i<n; i++ ){
                int curr = nums[i];
                nums[i] = prev;
                prev = curr;
            }
            nums[0] = prev;
            k--;
        }
        
    }
};

// Optimized Approach

// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach: Use an auxiliary array to store the rotated version of the array.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> result(n);

        for (int i=0; i<n; i++){
            int new_i = (i+k)%n;
            result[new_i] = nums[i];
        }

        nums = result;
        
    }
};

/*

LEFT ROTATION : (i-k+n)%n
RIGHT ROTATION : (i+k)%n

*/

