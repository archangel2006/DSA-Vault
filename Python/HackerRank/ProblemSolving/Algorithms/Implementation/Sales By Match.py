#There is a large pile of socks that must be paired by color. 
# Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.
#Example
n=7
ar=[1,2,1,2,1,3,2]

#There is one pair of color  and one of color . There are three odd socks left, one of each color. The number of pairs is .


from collections import Counter

def sockMerchant(n, ar):
    # Write your code here
    count=0
    freq=Counter(ar)
    for key in freq:
        count+=freq[key]//2
    return count

