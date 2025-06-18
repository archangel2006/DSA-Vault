#June18,2025

class Solution:
    def maxArea(self, height) :
        if len(height)==2:
            return min(height)
    
        water=0
        for i in range(len(height)-1):
            if height[i]>height[i+1]:
                y=height[i]
                ind=i
                break
            else:
                y=height[i]
                ind=i  
        for x in range(ind+1,len(height)):
            z=min(y,height[x])
            area=z*(x-ind)
            water=max(water,area)
        return water
        