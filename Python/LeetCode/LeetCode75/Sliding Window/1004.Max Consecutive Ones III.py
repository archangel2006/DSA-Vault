#June22,2025

class Solution:
    def longestOnes(self, nums,k) :
        left,right=0,0
        zero=0
        length=0
        # Loop through the array using right pointer
        while right<len(nums):
            # If current right element is 0, we include it in the window and increment zero
            if nums[right]==0:
                zero+=1
            # If the window has more than k zeros, we need to shrink the window from the left
            while zero>k:
                if nums[left]==0:
                    zero-=1
                left+=1   # Move the left pointer to shrink the window
            # Update the max length of the valid window (right - left + 1)
            length = max(length, right - left + 1)
            # Expand the window from the right
            right+=1
        return length
        