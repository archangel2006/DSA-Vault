# June27,2025

'''
	A linked list node has the following structure
	{
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	}
'''
#Function to find the data of kth node from the end of a linked list
class Solution:
    def getKthFromLast(self, head, k):
        def length():
            l=0  # O(1)
            current=head # O(1)
            while current: # O(n)
                l+=1 # O(1)
                current=current.next # O(1)
            return l # O(1)
            
        n= length() # O(l)
        if n<k or k<=0: # O(1)
            return -1
        pointer=head # O(1)
        for i in range(n-k): # O(l-k)
            pointer=pointer.next # O(1)
            
        return pointer.data # O(1)
        
        # Time Complexity : O(n)
        # SPace Complexity : O(1)

# Companies: Flipkartl MorganStanley, Accolite, Amazon, OYO Rooms,
# Samsung, Snapdeal, FactSet, Hike, MAQ Software, Adobe, Qualcomm,
# Epic Systems, Citicorp, Monotype Solutions
            
                
                