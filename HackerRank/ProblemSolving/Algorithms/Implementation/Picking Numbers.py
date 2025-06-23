def pickingNumbers(a):
    # a.sort()  #changes array , not effecient
    # actually now that I understand the Q, we can use sort!
    
    length=0
    unique=sorted(set(a))
    for i in range(len(unique)-1):
        if abs(unique[i]-unique[i+1])<=1:
            x= a.count(unique[i])+a.count(unique[i+1])
            length=max(length,x)
            
    return length


from collections import Counter 
def pickingNumbers(a):
    freq =Counter(a)
    length=0
    for key in freq:
        length=max(length,freq[key]+freq.get(key+1,0)) #dict.get(key, default)
        # key: the key you’re looking up.
        # default_value: what to return if the key doesn't exist in the dictionary.
        # If default_value is not provided, it returns None by default.
    return length
    
    