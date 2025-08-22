# June26,2025

class SinglyLinkedListNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        
def insertNodeAtPosition(llist, data, position):
    new_node=SinglyLinkedListNode(data)
    
    prev=None
    i=0
    current=llist
    while current and i<position:
        i+=1
        prev=current
        current=current.next
    prev.next=new_node
    new_node.next=current
    
    return llist