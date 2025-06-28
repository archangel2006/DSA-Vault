class Node:
    def __init__(self,data):
        self.data=data
        self.next=next


class Solution:
    def detectCycle(self, head):
        fast=slow=head #O(1)
        while fast and fast.next: # O(n)
            slow=slow.next #O(1)
            fast=fast.next.next # O(1)
            if slow==fast: #O(1)
                # Cycle detected, now find start of the cycle
                slow = head # O(1)
                while slow != fast: #O(n) 
                    slow = slow.next #O(1)
                    fast = fast.next #O(1)
                
                return slow
            
        return None
    
    # Time Complexity: O(n)
    # Space Complexity: O(1)
        