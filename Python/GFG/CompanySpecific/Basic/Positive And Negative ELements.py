# June 24,2025

## ALternate solution below


# SOl1 : MOdifying In PLace
class Solution:
    def arranged(self,arr):
        positive=[] # SPace:O(n)
        negative=[] # Space:O(n)
            
        for num in arr: #O(n)
            if num>0: # O(1)
                positive.append(num) # O(1)
            else:
                negative.append(num) # O(1)
                
        if len(arr)==2: # COmparison : O(n)
            arr[0]=positive[0]  # Assigning : O(1)
            arr[1]=negative[0]  # Assigning : O(1)
            return arr
            
        for i in range(0,len(arr),2):  # O(n/2)=O(n)
                arr[i]=positive[0] # O(1)
                positive.pop(0) # O(n)
                arr[i+1]=negative[0] # O(1)
                negative.pop(0) # O(n)
                
        return arr
    
# Returning New Array
class Solution:
    def arranged(self,arr):
        # Note: Modifying in place is not necessary!!!
        
        positive=[x for x in arr if x>0] # SPace:O(n)
        negative=[y for y in arr if y<0] # Space:O(n)
        res=[]
            
        #for num in arr: #O(n)
        #    if num>0: # O(1)
        #        positive.append(num) # O(1)
        #    else:
        #        negative.append(num) # O(1)
             
        for i in range(len(positive)):
            res.append(positive[i])
            res.append(negative[i])
            
        return res
            

# Note: L.pop(0) runs in O(n) time. 
# Python removes the first element and then shifts every other element left by one position to fill the gap.

# # # # # # # # Can go through this swapping route # # # # # # # # # # 
class Solution:
    def arranged(self,arr):
        positive=0
        negative=0
        
        for i in range(len(arr)):
            if positive!=0:
                if arr[i]>0:
                    positive=1
            if negative!=0:
                if arr[i]<0:
                    negative=i
            if positive!=0 and negative!=0:
                break
        while negative <len(arr) and positive<len(arr):
            break ### not actually, write code here