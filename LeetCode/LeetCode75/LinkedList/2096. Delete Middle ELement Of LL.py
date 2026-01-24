# June26.2025

# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def deleteMiddle(self, head):
        if head is None or head.next is None:
            return None
        prev=None
        p2,p1=head,head
        while p2 and p2.next:
            prev=p1
            p1=p1.next
            p2=p2.next
            p2=p2.next

        prev.next=p1.next
        return head