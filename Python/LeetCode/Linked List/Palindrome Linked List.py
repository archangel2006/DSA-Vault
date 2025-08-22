# June28,2025

#  Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        current=head # O(1)
        values=[] # Space: O(n)
        while current: # Time: O(n)
            values.append(current.val) # O(1)
            current=current.next # O(1)
        
        return values[::-1]==values #O(n)

        # Time: O(n)
        # Space: O(n)
        