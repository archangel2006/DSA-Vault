
class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None
        
class Solution():
    def flatten(self,root):
        if root is None or root.next is None:
            return root
        current=root
        while current:
            down=current
            while down:
                print(current.bottom,end='->')
                down=down.bottom
            current=current.next
            