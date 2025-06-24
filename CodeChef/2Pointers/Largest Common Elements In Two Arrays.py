def largestCommonElement(arr1, arr2):
    arr1.sort(reverse=True)
    arr2.sort(reverse=True)
    pointer=0
    if n<=m:
        while pointer<n:
            if arr1[pointer] in arr2:
                return arr1[pointer]
            else:
                pointer+=1
    else:
        while pointer<m:
            if arr2[pointer] in arr1:
                return arr2[pointer]
            else:
                pointer+=1
    return -1

if __name__ == "__main__":
    n, m = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))
    print(largestCommonElement(arr1, arr2))