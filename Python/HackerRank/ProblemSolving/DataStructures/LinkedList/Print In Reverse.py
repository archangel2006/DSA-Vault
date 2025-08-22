# June27, 2025

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
def reversePrint(llist):
    values=[]
    current=llist
    while current:
        values.append(current.data)
        current=current.next
        
    # return (x for x in values[::-1])  # doesn't print
    # print (x for x in values[::-1]) # prints generator object too, which we don't want
    
    for x in values[::-1]:
        print(x)