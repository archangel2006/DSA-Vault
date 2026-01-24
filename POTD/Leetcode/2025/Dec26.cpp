// 2483. Minimum Penalty for a Shop

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;

        // Step 1: initial penalty (closing at hour 0)
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Step 2: move closing hour forward
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;   // satisfied customer
            } else {
                penalty++;   // unhappy customer
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
