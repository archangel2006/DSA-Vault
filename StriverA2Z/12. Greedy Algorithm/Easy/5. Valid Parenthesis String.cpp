#include bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool checkValidString(string s) {

        int minOpen = 0;   // min possible '('
        int maxOpen = 0;   // max possible '('

        for (char c : s){
            if (c == '('){
                minOpen++;
                maxOpen++;
            }else if (c == ')'){
                minOpen--;
                maxOpen--;
            }else{
                minOpen--;  // * = )
                maxOpen++;  // * = (
            }

            if (maxOpen < 0){
                return false;
            }
            if (minOpen < 0){
                minOpen = 0;
            }
        }
        
        return minOpen == 0;
    }
};