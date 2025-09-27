#include <iostream>
#include <vector>
using namespace std;

class Solution {
  private:
    void helper(string& s, int start, int end){
        if (start >= end){
            return;
        }
        swap(s[end],s[start]);
        
        helper(s, start+1, end-1);
    }
  public:
    bool isPalindrome(string& s) {
        string initial = s;
        helper(s, 0, s.length()-1);
        return s == initial;
        
    }
};

//Time : 0.02s