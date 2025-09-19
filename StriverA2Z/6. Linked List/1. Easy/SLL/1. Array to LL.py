
# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def arrayToList(self, arr):
        # code here
        head=Node(arr[0])
        curr=head
        for num in arr[1:]:
            curr.next = Node(num)
            curr = curr.next
            
        return head


# Time: 1.29sec     
            
        
        