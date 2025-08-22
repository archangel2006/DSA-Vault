from collections import Counter

class Solution:
	def search(self,pat, txt):
		k=len(pat)
		n=len(txt)
		if k>n:
			return 0
		count=0
		window=txt[:k]
		pat_freq=Counter(pat) # Frequency of characters in the pattern
		for i in range(n-k):
			if Counter(window) == pat_freq:
				count+=1
				window = window[1:]+txt[i+k]
	        
	    # Final window check (last one not checked in the loop)
        # if Counter(window) == pat_freq:
		count+=1
		return count
   
	 #Companies:Flipkart, Amazon, Microsoft, Intuit