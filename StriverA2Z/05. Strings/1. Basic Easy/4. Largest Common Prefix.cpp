#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
1. strs – This is presumably a vector<string> (or any container of strings). 
For example: vector<string> strs = {"apple", "banana", "kiwi"};

2. sort(strs.begin(), strs.end(), ...) – This calls the C++ standard library sort function to sort elements from strs.begin() to strs.end(). So it sorts the whole vector strs.

3. [](string a, string b) { return a.length() < b.length(); } – This is a lambda function.
        - [] means it’s a lambda.
        - (string a, string b) are the inputs (two strings from the vector to compare).
        - return a.length() < b.length(); is the comparison logic.

In words: compare two strings by their length and return true if the first string is shorter than the second.

4. Effect: After this sort, the vector strs will be ordered by string length, shortest to longest.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans="";

        // edge case
        if (strs.size()<1){
            return ans;
        }else if(strs.size() == 1){
            return strs[0];
        }
        vector<int> prefixes;

        // sort words based on size
        sort(strs.begin(), strs.end(), [](string a, string b) {return a.length() < b.length(); }); 

        string s1 = strs[0];  // pick smallest string
        int n = s1.size();
        
        bool flag=true;
        for (int i=0; i<=n; i++){
            // string.substr(start_index, length)
            string sub = s1.substr(0,i);
            for (string word : strs){
                if (!word.starts_with(sub)){
                    flag = false; break;
                }
            }
            if (flag) ans = sub;
            flag = true;  
        }
        return ans;
    }
};