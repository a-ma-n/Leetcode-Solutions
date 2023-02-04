from functools import cache
class Solution:
    def numDistinct(self, s1: str, s2: str) -> int:
        l1,l2=len(s1),len(s2)
        @cache
        def countUtil(ind1,ind2):
            if ind2<0: return 1
            if ind1<0: return 0
            
            if s1[ind1]==s2[ind2]:
                leaveOne=countUtil(ind1-1,ind2-1)
                stay=countUtil(ind1-1,ind2)
                
                return leaveOne+stay
                
            return countUtil(ind1-1,ind2)
        return countUtil(l1-1,l2-1)
            
            