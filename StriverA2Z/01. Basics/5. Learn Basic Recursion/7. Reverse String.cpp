#include <iostream>
#include <vector>
using namespace std;    


// Time: 0.02s
class Solution {
  public:
    string reverseString(string& s) {
        int n = s.length();
        if (n==0 || n==1){
            return s;
        }else{
            int start = 0;
            int end = n-1;
            while (start < end){
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }
        return s;
        
        
    }
};




// RECURSIVE APPROACH

// 1010 /1111 test cases passed

class Solution {
  public:
    string reverseString(string& s) {
        int n = s.length();
        if (n<=1){
            return s;
        }else{
            // Take substring from 1 to end (omit first char)
            string rest = s.substr(1);
        
            // Recursive call on the rest of the string
            string reversedRest = reverseString(rest);
            
            // Append the first char at the end (this builds reversal)
            return reversedRest + s[0];
        }
        
        
    }
};

// Using Helper Function


class Solution {
  private:
    void helper(string& s, int start, int end){
        // Base Case
        if (start >= end ){
            return;
        }
        swap(s[start],s[end]);
         
        // recursive step 
        helper(s, start+1, end-1);
    }
  public:
    string reverseString(string& s) {
        helper(s, 0, s.length() - 1);
        return s;
    }
};
