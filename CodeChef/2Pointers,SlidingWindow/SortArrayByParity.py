
def sortArrayByParity(nums):
    for i in range(len(nums)):
        if nums[i]%2==0:
            p=i
            odd=i-1
            break
        else:
            return nums
    
    while p<len(nums)-1:
        if nums[p+1]%2!=0:
            nums.insert(odd+1,nums[p+1])
            nums.pop(p+2)
            odd+=1
        else:
            p+=1
    return nums   

if __name__ == "__main__":
    N = int(input())
    nums = list(map(int, input().split()))

    sortArrayByParity(nums)

    print(" ".join(map(str, nums)))

    #2

def sortArrayByParity(nums):
    
    even=[]
    odd=[]
    
    for num in nums:
        if num%2==0:
            even.append(num)
        else:
            odd.append(num)
    for i in range(len(odd)):
        nums[i]=odd[i]
    for j in range(len(even)):
        nums[j+len(odd)]=even[j]
 
            
if __name__ == "__main__":
    N = int(input())
    nums = list(map(int, input().split()))

    sortArrayByParity(nums)

    print(" ".join(map(str, nums)))
            