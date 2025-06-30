# June30,2025

n=int(input())
import numpy as np
L=[]
for i in range(1,n*n+1):
    L.append(i)
arr=np.array(L)
arr=arr.reshape(n,n)
print(' '.join(map(str, arr.flatten())))