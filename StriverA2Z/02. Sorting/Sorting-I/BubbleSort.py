class Solution:
    def bubbleSort(self,arr):
        n = len(arr)
        for i in range(n-1):
            for j in range(n-i-1):
                if arr[j]>arr[j+1]:
                    arr[j],arr[j+1] = arr[j+1],arr[j]
                    
        return arr
                    
                    
# Time : 0.81 sec                  
    # In every pass, we process only those elements that have already not moved to correct position. After k passes, the largest k elements must have been moved to the last k positions