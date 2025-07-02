# June2,2025

'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''
'''
    head1:  head of linkedList 1
    head2:  head of linkedList 2
    n1:  len of  linkedList 1
    n2:  len of linkedList 1
    x:   given sum
'''
class Solution:
    def countPairs(self, head1, head2, x):
        set1=set() # O(n)
        set2=set() # O(n)
        current=head1 # O(1)
        while current: # O(n1)
            set1.add(current.data) # O(1)
            current=current.next
        current=head2
        while current: # O(n2)
            set2.add(current.data) # O(1)
            current=current.next
            
        count=0 # O(1)
        
        if len(set1)<len(set2):
            for val in set1: # O(n1)
                if x-val in set2: # O(1)
                    count+=1 #O(1)
        else:
            for val in set2: # O(n2)
                if x-val in set1: # O(1)
                    count+=1 # O(1)
        return count   # O(1)
                