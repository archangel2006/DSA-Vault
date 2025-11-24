import math

# 27 / 47 testcases passed

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        i = 0
        d = {}
        while (i<len(s)):
            if s[i]!=t[i]:
                if s[i] in d and d[s[i]]!=t[i]:
                    return False
                else:
                    d[s[i]] = t[i]
            
            i+=1
        return True                
        
# 42 / 47 testcases passed

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        i = 0
        d = {}
        while (i<len(s)):
            if s[i]!=t[i]:
                if s[i] in d and d[s[i]]!=t[i]:
                    return False
                else:
                    d[s[i]] = t[i]
            else:
                d[s[i]] = t[i]
            i+=1

        i = 0
        d2 = {}
        while (i<len(s)):
            if t[i]!=s[i]:
                if t[i] in d2 and d2[t[i]]!=s[i]:
                    return False
                else:
                    d2[t[i]] = s[i]     
            else:
                d2[t[i]] = s[i]
            i+=1

        return True                
        
# 47 / 47 testcases passed

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        i = 0
        d = {}
        while (i<len(s)):
            if s[i]!=t[i]: # s[i] doesn't match t[i]
                if s[i] in d and d[s[i]]!=t[i]: # s[i] exists in d, but doesn't match with t[i]
                    return False # not isomorphic
                else: # if s[i] doesn't exist in d, map it to t[i]
                    d[s[i]] = t[i]
            else: # s[i] = t[i]
                if s[i] in d: # check of already mapped with someone else
                    if d[s[i]]!=s[i]: # if mapped with someone besides itself
                        return False # can't make double mapping
                d[s[i]] = t[i] # if s[i] not in d, map it to itself
            i+=1

        i = 0
        d2 = {}
        while (i<len(s)):
            if t[i]!=s[i]:
                if t[i] in d2 and d2[t[i]]!=s[i]:
                    return False
                else:
                    d2[t[i]] = s[i]     
            else:
                if t[i] in d2:
                    if d2[t[i]]!=t[i]:
                        return False
                d2[t[i]] = s[i]
            i+=1

        return True                
        