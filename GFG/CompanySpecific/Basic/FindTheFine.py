#June18,2025


class Solution:
    def totalFine(self, date, car, fine):
        
        tot=0
        
        if date%2==0:
            for i in range(len(car)):
                if car[i]%2!=0:
                    tot+=fine[i]
        if date%2!=0:
            for i in range(len(car)):
                if car[i]%2==0:
                    tot+=fine[i]
                    
        return tot
                
    
    
    