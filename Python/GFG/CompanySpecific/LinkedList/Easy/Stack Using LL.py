# June2,2025
class MyStack:
    def __init__(self):
        self.head=None

    class StackNode:
        def __init__(self, data):
            self.data = data
            self.next = None
        
    #Function to push an integer into the stack.
    def push(self, data):
        new_node=StackNode(data)
        new_node.next=self.head
        self.head=new_node
        
    #Function to remove an item from top of the stack.
    def pop(self):
        if self.head is None:
            return -1
        else:
            x=self.head.data
            self.head = self.head.next
            return x
            
# Companies: Microsoft, Samsung, FactSet, SAP Labs, Codenation