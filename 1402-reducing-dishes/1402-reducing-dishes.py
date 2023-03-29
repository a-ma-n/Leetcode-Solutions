class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        n=len(satisfaction)
        
        @cache
        def findMax(ind,time=0):
            #base cases
            if ind>n-1:
                return 0
            
            pick=satisfaction[ind]*(time+1)+findMax(ind+1,time+1)
            
            notpick=findMax(ind+1,time)
            
            return max(pick,notpick)
        
        return findMax(0)