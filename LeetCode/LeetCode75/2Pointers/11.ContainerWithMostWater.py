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
        

#So why do we always move the pointer of the smallest pillar?
#The reason for this is simple. There is no reason to hang onto the pillar of the smallest size in the current range because in the next iteration, the overall width will decrease by one. Thus, a potential greater area will never be reached by hanging onto the smaller pillar, because even if another taller pillar is found by moving the pointer at the taller pillar, the area must always be calculated with the minimum of the two pillars. Due to the smaller width by decreasing the pointer range, the overall area will be smaller regardless. Thus, we can safely disregard the smaller pillar at each iteration.

class Solution:
    def maxArea(self, height: List[int]) -> int:
        start,end=0,len(height)-1
        water=min(height[start],height[end])*(end-start)
        while start<end:
            area=min(height[start],height[end])*(end-start)
            if height[start]<height[end]:
                start+=1
            else:
                end-=1
            water=(max(area,water))
        return water

