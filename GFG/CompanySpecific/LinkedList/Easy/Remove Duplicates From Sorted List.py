# June27,2025

'''
	Your task is to remove duplicates from given 
	sorted linked list.
	
	Function Arguments: head (head of the given linked list) 
	Return Type: none, just remove the duplicates from the list.
'''
		# Node Class
class Node:
	def __init__(self, data):   # data -> value stored in node
		self.data = data
		self.next = None


#Function to remove duplicates from sorted linked list.
def removeDuplicates(head):
    seen=set()
    current=head
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
    return head

# Companies: Microsoft, OYO Rooms, Oracle, Visa, Adobe, Myntra