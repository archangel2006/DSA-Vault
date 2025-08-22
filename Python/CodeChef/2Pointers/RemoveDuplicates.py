
n=int(input())
a=list(map(int,input().split()))
    #  SORTED ARRAY !!!
pointer=1        # starting at 2nd
visited=a[0]     # storing 1st element as visited
while pointer<len(a):  #iterating using pointer
    if a[pointer] == visited:   #if pointer is already visited
        a.pop(pointer)   # remove the value # pointer remains at same position
    else:
        visited=a[pointer]  # otherwise new visited becomes that value
        pointer+=1  #and increase the pointer to point to next value
            
print(len(a))
print(' '.join(map(str,a)))
        
        