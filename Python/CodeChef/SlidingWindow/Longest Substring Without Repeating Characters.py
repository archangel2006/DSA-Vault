# June24,2025
s=input()
n=len(s)

from collections import Counter
left,right=0,0
length=0
freq={}
while right<n:
    if s[right] not in freq:
        freq[s[right]]=1
        right+=1
    else:
        freq.pop(s[left])
        left+=1
    length=max(length,right-left)
print(length)
