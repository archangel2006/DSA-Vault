#June19,2025

class Solution:
    def getPairs(self, arr):
        
        arr.sort()  #O(nlogn)
        result=[]
        i=0
        while i<len(arr):  #O(n)
            for j in range(i,len(arr)): #O(n-i)=O(n)
                if i!=j and arr[i]+arr[j]==0 : 
                    if [arr[i],arr[j]] not in result and [arr[j],arr[i]] not in result: #O(n)
                        result.append([arr[i],arr[j]])
            i+=1
       
        return result
        
        #Time COmplexity= O(n^3)
             

    # Companies: Flipkart, Accolite, Amazon, FactSet, Hike
    # MakeMyTrip, Goldman Sachs, Adobe, Salesforce
    


class Solution:
    def getPairs(self, arr):
        result=[]
        arr.sort()  #O(nlogn)
        seen_pair=set()
        left=0
        right=len(arr)-1
        while left<right: #O(n)
            sum=arr[left]+arr[right]
            if sum>0:
                right-=1
            elif sum<0:
                left+=1
            else:
                pair=(arr[left],arr[right])  #Tuples Are Hashable, Lists Are Not
                #store current values before moving pointers
                if pair not in seen_pair:
                    seen_pair.add(pair)
                    result.append([arr[left],arr[right]])
                right-=1
                left+=1
        return result
        
    # Companies: Flipkart, Accolite, Amazon, FactSet, Hike
    # MakeMyTrip, Goldman Sachs, Adobe, Salesforce
    
    