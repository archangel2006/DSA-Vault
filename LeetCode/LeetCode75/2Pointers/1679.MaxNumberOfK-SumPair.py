#June19,2025

class Solution:
    def maxOperations(self, nums,k) -> int:
        count,i=0,0
        while i<len(nums): #O(n)
            if nums[i] is None:
                i += 1
                continue
            for j in range(len(nums)): #O(n)
                if nums[j] is not None and i!=j :
                    if nums[i]+nums[j]==k:
                        nums[i]=None
                        nums[j]=None
                        count+=1
                        break
            i+=1        
        return count
        

class Solution:
    def maxOperations(self, nums,k):
        
        count=0
        freq=Counter(nums)
        for num in freq:
            complement=k-num
            if num==complement: #if 2 same nums add upto k, 3+3=6
                count+=freq[num]//2
            elif num<complement: # to avoid double counting of pairs
                count+=min(freq[num],freq[complement])
        return count
        