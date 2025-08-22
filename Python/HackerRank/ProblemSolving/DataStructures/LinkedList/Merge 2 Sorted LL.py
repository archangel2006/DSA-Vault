# June 27,2025

class SinglyLinkedListNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        
def mergeLists(head1, head2):
    current1=head1
    current2=head2
    sortedLL = SinglyLinkedListNode(-1)
    #sortedLL=None
    current=sortedLL
    
    while current1 and current2:
        if current1.data > current2.data:
            current.next=SinglyLinkedListNode(current2.data)
            current2=current2.next
        else:
            current.next=SinglyLinkedListNode(current1.data)
            current1=current1.next
        current=current.next 
        
    if current1:
        while current1:
            current.next=SinglyLinkedListNode(current1.data)
            current1=current1.next
            current=current.next 
            
    elif current2:
        while current2:
            current.next=SinglyLinkedListNode(current2.data)
            current2=current2.next
            current=current.next 
        
    return sortedLL.next
        
        