# June28,2025

'''
# node class:

class Node:
    def __init__(self,val):
        self.next=None
        self.data=val

'''

class Solution:
    def removeLoop(self, head):
        slow = fast = head
        # Step 1: Detect loop using the two-pointer technique
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast: # Loop detected
                # Step 2: Move one pointer to head
                slow = head
                if slow == fast:
                    # Special case: loop starts at head
                    # Move fast to the node just before the start of the loop
                    while fast.next != slow:
                        fast = fast.next
                else:
                    # General case: move both pointers one step at a time
                    # until their next pointers meet
                    while slow.next != fast.next:
                        slow = slow.next
                        fast = fast.next
                # Step 3: Break the loop
                fast.next = None
                return  # Loop removed; exit the function
        # If while loop exits normally, no loop was found
                

        # Companies: VMWare, MorganStanley, Amazon, Microsoft, 
        # Snapdeal, MakeMyTrip, Oracle, Walmart, Goldman Sachs
        # Adobe, Qualcomm, Kuliza, Netskope
            