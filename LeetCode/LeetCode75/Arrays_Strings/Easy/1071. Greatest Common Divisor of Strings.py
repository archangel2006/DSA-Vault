#June19,2025


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        min_len = min(len(str1), len(str2))
        
        for i in range(min_len, 0, -1):
            # Candidate prefix
            candidate = str1[:i]
            
            # Check if lengths are divisible
            if len(str1) % i == 0 and len(str2) % i == 0:
                
                # Generate repeated strings from candidate
                repeat1 = candidate * (len(str1) // i)
                repeat2 = candidate * (len(str2) // i)
                
                if repeat1 == str1 and repeat2 == str2:
                    return candidate
                    
        return ""



class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # Step 1: Check if they have the same pattern
        if str1 + str2 != str2 + str1:
            return ""
        
        # Step 2: Return prefix with GCD length
        gcd_len = math.gcd(len(str1), len(str2))
        return str1[:gcd_len]
    
#    🔁 Recursive GCD (Euclidean Algorithm):

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
# This recursive approach is tail-recursive, and very efficient. 
# Its time complexity is O(log(min(a, b))), so recursion here does not increase time complexity significantly.