# June26,2025

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

def compare_lists(llist1, llist2):
    current1=llist1
    current2=llist2
    while current2 and current1:
        if current2.data==current1.data:
            current1=current1.next
            current2=current2.next
        else:
            return 0
    if current1==current2:
        return 1
    else:
        return 0