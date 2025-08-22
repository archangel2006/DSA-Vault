# June26,2025

'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

# Time Limit Exceeds for Larger Output

class Solution:
    def deleteMid(self, head):
        
        prev=None # O(1)
        p1,p2=head,head # O(1)
        
        while p2 and p2.next: # O(n/2)
            prev=p1 #O(1)
            p1=p1.next #O(1)
            p2=p2.next #O(1)
            p2=p2.next #O(1)
            
        prev.next=p1.next # O(1)
        del(p1) #O(1)
        
        return head
            
    # Companies: Flipkart, Amazon, Microsoft
    # Time Complexity: O(n)
    # Space Complexity: O(1)
    
# del(p1)-causes a runtime error for large inputs because it may trigger deep garbage collection, and Python uses recursion to clean up, which can exceed the recursion limit and crash.