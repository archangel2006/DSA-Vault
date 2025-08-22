# June26,2025


class SinglyLinkedListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertNodeAtTail(head, data):
    if head is None:
        return SinglyLinkedListNode(data)
    current=head
    while current.next:
        current=current.next
    current.next=SinglyLinkedListNode(data)
    return head
    