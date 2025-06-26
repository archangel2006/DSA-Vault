# June26,2025

''' structure of node:

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

'''

class Solution:
    def findIntersection(self,head1,head2):
        intersection=None
        current1,current2=head1,head2 #O(1)
        common=[] 
        set2=set()
        while current2: #O(m)
            set2.add(current2.data) #O(1)
            current2=current2.next
        while current1: #O(n)
            if current1.data in set2: # O(1)
                common.append(current1.data) #O(1)
            current1=current1.next
        current=intersection
        for num in common: #O(k:common elements)
            if intersection:
                current.next=Node(num)
                current=current.next
                
            else:
                intersection=Node(num)
                current=intersection
        if current:
            current.next=None
        return intersection
        # Companies: Amazon, Microsoft, D-E-Shaw, Zopper
        #Time Complexity : O(m+n+k)
        # Space Complexity: O(m+k) ,  m for set, k for array and LL