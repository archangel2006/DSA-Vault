


class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None

# .next and .bottom are different even though linked by chains.      
class Solution:
    def flatten(self, root):
        current=root
        while current:
            down=current
            while down.bottom:
                down=down.bottom
            
            current=current.next
            down.next=current
        return root
                
        
# DOESN'T SORT VALUES
class Solution:
    def flatten(self, root):
        current=root
        while current:
            new=current.next
            down=current
            while down.bottom:
                down.next=down.bottom
                down=down.bottom
            down.next=new
            current=new
        return root
