class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def getMiddleElement(head):
    p1=head
    p2=head
    while p2 and p2.next:
        p1=p1.next
        p2=p2.next.next
    
    return p1.data
    
    