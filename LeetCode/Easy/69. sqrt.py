class Solution:
    def mySqrt(self, x: int) -> int:
        
        i=1
        while True:
            if i*i == x:
                return i
            elif i*i<x:
                return i+1
            else:
                return i-1
            i+=1
 
class Solution:
    def mySqrt(self, x: int) -> int:
        i=0
        while i*i<=x:  # runs sqrt(x) times - O(n)
            if i*i==x:
                return i
            i+=1
        return i-1

        #Time Complexity : O(n) or O(x^0.5)
        # Space Compelxity : O(1)

class Solution:
    def mySqrt(self, x: int) -> int:
        if x==1 or x==0:  # base cases
            return x
        low,high=0,x
        while low<=high:   # logic similar to binary search
            mid=(low+high)//2
            if mid*mid==x:
                return mid
            elif x<mid*mid:
                high=mid-1
            else:
                low=mid+1
        
        return high

        # Time COmplexity: O(logx)

