# cook your dish here

t=int(input())
while t>0:
    t-=1
    
    n,b=map(int,input().split())
    a=list(map(int,input().split()))
    
    pointer=0
    while pointer<n:
        target1=b+a[pointer]
        target2=-b+a[pointer]
        if (target1 in a and target1 != a[pointer]) or (target2 in a and target2 != a[pointer]):
            print(1)
            break
        else:
            pointer+=1
    if pointer==n:
        print(0)
        
        
        