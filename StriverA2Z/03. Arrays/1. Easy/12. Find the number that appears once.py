class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        freq = {}
        for i in nums:
            if i not in freq:
                freq[i] = 1
            else:
                freq[i]+=1

        for key in freq:
            if freq[key] == 1:
                return key

# Time : O(n) 


#IDK if this works or not...will improve on this 
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        i, cnt, j = 0,0,0
        n = len(nums)
        while i<n and j<n:
            cnt=1
            j=i+1
            if nums[j]!=nums[i]:
                j+=1
            elif nums[i] == nums[j]:
                i+=1
                j+=1

        return nums[i]
        