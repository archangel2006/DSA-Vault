
n,k=map(int,input().split())
arr=list(map(int,input().split()))

window_sum=sum(arr[:k])
max_sum=window_sum

for i in range(n-k):
    window_sum+=arr[i+k]-arr[i]
    max_sum=max(window_sum,max_sum)
    
print(max_sum)
