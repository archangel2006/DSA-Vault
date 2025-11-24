from typing import List


# Time Complexity : O(N * M) where N is the number of strings and M is the length of the longest string.
# Space Complexity : O(M) for storing prefixes of the first string.


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefixes = []  # empty list to stire prefixes
        string1 = strs[0] # first string from the list

        # iterate over first string to obtain all its prefixes
        n = len(string1) 
        for i in range(1, n + 1):
            sub = string1[:i]
            prefixes.append(sub)

        # reversing the prefixes list to start checking from longest prefix
        prefixes.reverse()
        for prefix in prefixes:
            flag = True
            for string in strs:
                if string.startswith(prefix):
                    flag = True
                else:
                    flag = False
                    break
            if flag:
                return prefix
        return ""
