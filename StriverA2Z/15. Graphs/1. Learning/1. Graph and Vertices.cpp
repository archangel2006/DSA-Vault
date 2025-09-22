#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
  public:
    long long count(int n) {
        // your code here
        return  pow(2, n*(n-1)/2);
    }
};