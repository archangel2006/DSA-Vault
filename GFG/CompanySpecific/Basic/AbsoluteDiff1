#June18, 2025
#Redo

#User function Template for python3
class Solution:
    def getDigitDiff1AndLessK(self, arr, k):
        # code here
        result=[]
        i=0
        flag=True
        while i<len(arr):
            num=str(arr[i])
            if len(num)>=2 and int(num)<k:
                for j in range(len(num)-1):
                    if abs(int(num[j])-int(num[j+1]))!=1:
                        flag=False
                        break
                if flag==True:
                    result.append(int(num))
            flag=True
            
        return result
                        
                    