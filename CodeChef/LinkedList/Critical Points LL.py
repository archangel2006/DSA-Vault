class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
def solve(head):
    count=0
    prev=head
    current=head.next
    while current.next :
        if prev.val>current.val and current.next.val>current.val:
            count+=1
        elif prev.val<current.val and current.next.val<current.val:
            count+=1
        prev=current
        current=current.next
    return count