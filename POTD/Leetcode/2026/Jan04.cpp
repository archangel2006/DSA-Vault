// 1390. Four Divisors

#include<bits/stdc++.h>
using namespace std;


// BRUTE FORCE APPROACH

// Time Complexity: O(N * sqrt(M)) , where N is the size of the input array and M is the maximum element in the array.
// Space Complexity: O(1)

// Approach: Iterate through each number in the input array and for each number, find its divisors by checking all integers from 1 to the square root of the number. If a number has exactly four divisors, sum them up and add to the final answer.
// We use an unordered_set to store the divisors to avoid duplicates.
// Finally, return the total sum of divisors for all numbers in the input array.

class Solution {
private:
    int count4Divisors(int n){

        unordered_set<int>divisors;
        int sum=0;

        for (int i=1; i*i<=n; i++){
            if (n%i == 0){
                divisors.insert(i);
                divisors.insert(n/i);
            }

        }
        
        if (divisors.size()==4){
            for (int n : divisors){
                sum+= n;
            }
        }
        return sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int num : nums){
            ans+= count4Divisors(num);
        }

        return ans;
    }
};