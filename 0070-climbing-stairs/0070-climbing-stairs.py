class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def climb(index):
            if index==n-1:
                return 1
            elif index==n:
                return 1
            return climb(index+1)+climb(index+2)
        
        return climb(0)
            
        