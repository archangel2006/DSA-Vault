# June22,2025

class Solution:
    def maxOfSubarrays(self, arr, k):
        # code here
        n=len(arr) #O(1)
        window=arr[:k] #O(k): creating arr of size k
        max_value=[max(window)] # O(k): traversing
        
        for i in range(n-k):   # O(n-k)
            window=arr[i+1:i+k+1]  # O(k):slicing - list of size k
            max_value.append(max(window)) # O(k)
            
        return max_value
        
        #Time Complexity:(n - k) * O(k) = O(k * (n - k)) ≈ O(nk)
            
        
        # Companies: Flipkart, Amazon, Microsoft, Directi, Google
        

class Solution:
    def maxOfSubarrays(self, arr, k):
        # code here
        n=len(arr) #O(1)
        window_max=max(arr[:k]) #O(k): creating arr of size k
        max_value=[window_max] # O(1)
        
        for i in range(n-k):   # O(n-k)
            if arr[i]==window_max: #O(1):comparision
                window_max=max(arr[i+1:i+k+1]) #O(k):slicing and max
            else:
                window_max=max(window_max,arr[i+k]) #O(1)
            max_value.append(window_max) #O(1)
                
            #if arr[i+k]>=window_max:
            #    window_max=arr[i+k]
            #    max_value.append(window_max)
            
        return max_value
        
        #Time Complexity
        #   Worst Case: O(nk), when the max of the window leaves and must be recomputed each time
        #   Best Case:  O(n), when the current max never leaves the window and we just compare
        # Space Complexity:
        #   O(n - k + 1) for storing the output
            
        # Companies: Flipkart, Amazon, Microsoft, Directi, Google
        