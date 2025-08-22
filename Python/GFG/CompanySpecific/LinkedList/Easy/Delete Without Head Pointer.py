#June26,2025

'''
    Your task is to delete the given node from
	the linked list, without using head pointer.
	
	Function Arguments: node (given node to be deleted) 
	Return Type: None, just delete the given node from the linked list.

	{
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	}
'''
class Solution:
    # Function to delete a node in the middle of a singly linked list.
    def deleteNode(self, node):
        node.data=node.next.data # O(1)
        node.next=node.next.next #O(1)
        
        
        # Companies: Amazon, Microsoft, Samsung, Visa, Goldman Sachs, Kritikal Solutions