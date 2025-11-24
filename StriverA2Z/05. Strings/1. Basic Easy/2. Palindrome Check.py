

class Solution:
    def reverseWords(self, s: str) -> str:

        s = s.strip()   # remove leading and trailing spaces and returns a new string
        words = s.split(" ")  # splits words based on space and returns a list of words
        # but this also includes empty strings in the list if there are multiple spaces between words
        
        new_s = " ".join(words[::-1]) # joins the words in reverse order with a single space in between
        
        new_s = new_s.strip() #not actually required d

        return new_s
        

class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split() # splits words based on whitespace and removes extra spaces
        return " ".join(words[::-1]) # joins the words in reverse order with a single space in between