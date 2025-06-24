def count_pairs_less_than_x(arr, x):
    n=len(arr)
    p1=0
    p2=n-1
    count=0
    #sorted array!!
    while p1<p2:
        if arr[p1]+arr[p2]<x:
            count+=p2-p1
            p1+=1
        else:
            p2-=1
    return count
    
    
        
if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    x = int(input())
    print(count_pairs_less_than_x(arr, x))
