# June28,2025

# your task is to complete this function

'''
class node:
    def __init__(data):
        self.data = data
        self.next = None
'''
class Solution:
    #  Should return data of middle node. If linked list is empty, then  -1
    def getMiddle(self, head):
        slow=fast=head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
            
        return slow.data
        
        # Companies: VMWare, Zoho, Flipkart, MorganStanley, Amazon
        # Microsoft, Samsung, Hike, Payu, MAQ Software, Adobe, Wipro
        # SAP Labs, Qualcomm, Nagarro, GE, Veritas, Ignite, World, Netskope
