#June23,2025 

# Given a binary array nums, you should delete one element from it.
# Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

class Solution:
    def longestSubarray(self, nums):
        start=0  
        end=0
        length=0 # counting length of array
        del0=0  # count number of zeroes to delete
        while end<len(nums):  # iterating till the end of array
            if nums[end]==0:  # if zero encountered
                del0+=1       # we add zero count
            while del0>1:     # if number of zeroes exceed 1
                if nums[start]==0:   #to move the left side 1 place, if leftmost element is zero.
                    del0-=1  # we subtract zero count, leaving us with 1 zero again.
                start+=1   # we decrease the window size

            length=max(length,end-start+1) # now max length is max of prev length and new length.
            end+=1  # continue iteratiing through the loop by increasing rightmost pointer.
        return length-1 # -1 since we'll be deleting zero so removing it

            