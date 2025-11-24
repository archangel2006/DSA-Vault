
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for (char c:s){
            freq[c]++;

            // if (freq.find(character) != freq.end()){
            //     freq[character]+=1;
            // }else{
            //     freq[character]=1;
            // }
        }

        priority_queue<pair<int,char>> pq;
        for (auto &key : freq){
            pq.push({key.second, key.first});
        }

        string result = "";
        
        while (!pq.empty()){
            auto current = pq.top();
            pq.pop();

            char character = current.second;
            int frequency = current.first;

            for (int i=0; i<frequency; i++){
                result+=character;
            }
        }

        return result;
        
    }
};
