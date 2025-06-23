#June22,2025

class Solution:
    def findMaxConsecutiveOnes(self, nums) :
        # no limit to how many 0’s we can have, we can’t flip or ignore any 0. So every time we see a 0, we have to reset the window.
        
        consecutive_window=0 #O(1)
        max1=0 #O(1)
        for val in nums: #O(n)
            if val==0:
                consecutive_window=0 # reseting the window #(O(1))
            else:
                consecutive_window+=1 #O(1)
            max1=max(max1,consecutive_window) #O(1)

        return max1
        
        # Time COmplexity: O(n)