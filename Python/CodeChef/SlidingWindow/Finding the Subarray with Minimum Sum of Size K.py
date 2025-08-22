def findMinSumSubarray(n, k, arr):
    # Write your code here
    window_sum=sum(arr[:k])
    min_sum=window_sum
    
    for i in range(n-k):
        window_sum+=arr[i+k]-arr[i]
        min_sum=min(window_sum,min_sum)
        
    return min_sum


if __name__ == "__main__":
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(findMinSumSubarray(n, k, arr))
    
    
    