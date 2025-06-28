# 25June,2025

class Node:
    def init(self,val):
        self.data = val
        self.next = None

class Solution:
    def removeDuplicates(self, head):
        current = head
        seen = set()
        prev = None

        while current is not None:
            if current.data not in seen:
                seen.add(current.data)
                prev = current
            else:
                prev.next = current.next
            current = current.next

        return head