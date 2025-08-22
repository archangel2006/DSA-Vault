
t=int(input())
while t>0:
    t-=1
    
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    
    window_sum=sum(arr[:k])
    max_sum=window_sum
    for i in range(n-k):
        window_sum=window_sum-arr[i]+arr[i+k]
        max_sum=max(max_sum,window_sum)
    
    print(max_sum)