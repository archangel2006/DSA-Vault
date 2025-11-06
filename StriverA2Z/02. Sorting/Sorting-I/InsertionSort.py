class Solution:
    def insertionSort(self, arr):
        n = len(arr)
        for i in range(1,n):
            curr = arr[i]
            pointer = i-1
            while pointer>=0 and pointer<n:
                if curr < arr[pointer]:
                    arr[pointer+1] = arr [pointer]
                    pointer -=1
                else:
                    break
            arr[pointer+1] = curr
            

# Time : 0.21 sec


#  arr[pointer] = curr. When the while loop finishes, the pointer variable holds the index of the first element that was not shifted, or it becomes -1 if all elements were shifted. 
#  should be arr[pointer + 1] = curr.

