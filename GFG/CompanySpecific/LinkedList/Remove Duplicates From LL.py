#June25,2025

'''
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	
'''
class Solution:
    #Function to remove duplicates from unsorted linked list.
    def removeDuplicates(self, head):
        seen=set()
        current=head
        prev=None
        while current: #and current.next: # otherwise will skip last node
            if current.data not in seen:
                seen.add(current.data)
                prev=current
                
            else:
                prev.next=current.next
                #prev=current
                
            current=current.next
                
        return head