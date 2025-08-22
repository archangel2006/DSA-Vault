
class SinglyLinkedListNode:
    def __init__(self,data):
        self.data=data
        self.next=None

def deleteNode(llist, position):
    if position==0:
        return llist.next
    i=0
    prev=None
    current=llist
    while i<position:
        i+=1
        prev=current
        current=current.next
    prev.next=current.next
    return llist