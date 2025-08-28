class Solution:
    def findUnion(self, a, b):
        # code here 
        seta = set(a)
        setb = set(b)
        
        new = seta.union(setb)
        arr = list(new)
        
        arr.sort()
        
        return arr