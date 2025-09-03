#include <iostream>
using namespace std;


class Solution {
  public:
    int multiplication(int A, int B) {
        return A*B;        
    }
};

int main() {
    Solution S;
    cout <<S.multiplication(3,4) << endl;
    return 0;
}