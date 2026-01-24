# June27,2025


class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        def get_length():
            l=0  # O(1)
            current=head # O(1)
            while current: # O(n)
                l+=1 # O(1)
                current=current.next # O(1)
            return l # O(1)
            
        length= get_length() # O(l)
        if length<n or n<=0: # O(1)
            return 
        if n == length:
            return head.next

        prev=None
        pointer=head # O(1)
        for i in range(length-n): # O(l-k)
            prev=pointer
            pointer=pointer.next # O(1)
        
        
        #if pointer.next:
        #    prev.next=pointer.next
        #    return head
        #elif n==length:
        #    return head.next
        #else:
        #    prev.next=None # raises error if n=1, i.e, head

        if prev and pointer:
            prev.next=pointer.next
        return head
            
        

        