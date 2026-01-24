#Time Complexity: O(NKlogK) where N is the number of strings in the input list and K is the maximum length of a string in the input list. Sorting each string takes O(KlogK) time, and we do this for all N strings.
#Space Complexity: O(NK) where N is the number of strings in the input list

import collections
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        groups = defaultdict(list)

        for word in strs:
            key = tuple(sorted(word))
            groups[key].append(word)

        ans = []
        
        for key in groups:
            ans.append(groups[key]) 

        return ans