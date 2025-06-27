# June27,2025


class SinglyLinkedListNode:
    def __init__(self,data):
        self.data=data
        self.next=None

def removeDuplicates(llist):
    seen=set()
    current=llist
    prev=None
    while current:
        if current.data not in seen:
            seen.add(current.data)
            prev=current
            current=current.next
        else:
            current=current.next
            prev.next=current
            # alternate: prev.next = current.next  # Skip the duplicate
            # alternate: current = current.next    # Don't move prev
    return llist