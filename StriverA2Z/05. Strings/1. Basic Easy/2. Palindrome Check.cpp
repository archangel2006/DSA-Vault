#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        // remove leading and trailing spaces
        int start = s.find_first_not_of(' ');  // index of first nonspace char
        int end = s.find_last_not_of(' ');     // index of last nonspace char
        s = s.substr(start, end - start + 1);  // creates a substring from start to end index substr(pos, length)

        // split by whitespaces 
        stringstream ss(s);   // creates a stringstream taht allows to extract words seperated by spaces
        vector<string> words;
        string word;

        while (ss>>word){
            words.push_back(word);
        }

        // Reverse the words
        reverse(words.begin(), words.end());


        // Join with a single space
        string result; 
        for (int i = 0; i< words.size(); i++){
            result +=words[i];
            if (i+1 < words.size()) result += " ";  // add spcae only between words
        }

        return result;
    }
};