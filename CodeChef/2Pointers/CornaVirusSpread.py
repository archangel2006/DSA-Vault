#June19,2025

n=int(input())
arr=list(map(int,input().split()))
    
infected=[]

for i in range(n):
    count=1
    left,right=i-1,i+1
    while left>=0 and abs(arr[left]-arr[left+1])<=2:
        count+=1
        left-=1
    while right<n and abs(arr[right]-arr[right-1])<=2:
        count+=1
        right+=1
    infected.append(count)
        
print(min(infected),max(infected))
