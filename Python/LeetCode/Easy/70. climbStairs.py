# June24,2025

# Dynamic Programming

class Solution:
    def climbStairs(self, n: int) -> int:
        if n in memo: # if n stairs step is already in memo, simply return it
            return memo[n]
        if n<=2:  # base case n=2 and n=1
            return n
        memo[n]=self.climbStairs(n-1)+self.climbStairs(n-2) # recursion - jump 1 step from (n-1) or 2 steps from (n-2) - each will be then routed through more steps respectively.
        return memo[n]
        
memo={}       
 
# Time Complexity: O(n)
# Space Complexity: O(n)