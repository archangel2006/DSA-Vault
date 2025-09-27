#include <iostream>
#include <vector>
using namespace std;

// Recursive Final Output

class Solution {
  public:
    int fibonacciNumbers(int n) {
        // Base Case
        if (n<=2){
            return 1;
        }
        return fibonacciNumbers(n-1) + fibonacciNumbers(n-2); 
        
        
    }
};




  // Return list containing first n fibonacci numbers. 

class Solution {
  public:
  
    vector<int> fibonacciNumbers(int n) {
        // Base Case
        if (n==1) return {0};
        if (n==2) return {0,1};
        
        vector<int> fib = fibonacciNumbers(n - 1);
        
        // Add the next Fibonacci number
        int size = fib.size();
        fib.push_back(fib[size - 1] + fib[size - 2]);
        
        return fib;
    }
};

// Time: 0.01s

