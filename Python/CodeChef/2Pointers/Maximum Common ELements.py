# 
t=int(input())
while t>0:
    t-=1
    
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    
    count=0
    b=set(b)
    for num in a:
        if num in b:
            count+=1
    print(count)