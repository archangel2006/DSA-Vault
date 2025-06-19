#June19,2025

class Solution:
    def removeDuplicates(self, arr):
        pointer=1
        visited=arr[0]
        while pointer<len(arr): #O(n)
            
            if arr[pointer]==visited:
                arr.pop(pointer) #O(n)
            else:
                visited=arr[pointer]
                pointer+=1
        return len(arr)
        
                
        # Companies: Zoho, Morgan Stanley, Microsoft, 
        # Samsung, Google, Wipro, Xome
            

class Solution:
    def removeDuplicates(self, arr):
        start=0
        next=1
        
        while next<len(arr):
            if arr[start]==arr[next]:
                arr.pop(next)
            else:
                start+=1
                next+=1
            
        return len(arr)
                
    