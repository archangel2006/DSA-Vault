# June17,2025

class SinglyLinkedListNode:
    def __init__(self,data):
        self.data=data
        self.next=None
def reverse(llist):
    current=llist
    prev=None
    nex=current.next
    while nex:
        current.next=prev
        prev=current
        current=nex
        nex=nex.next  # skips the last node
    return prev