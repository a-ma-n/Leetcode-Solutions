from functools import cache
class Solution:
    def minDistance(self, s1: str, s2: str) -> int:
        
        @cache
        def editDistanceUtil(ind1,ind2):
            if ind1<0: return ind2+1
            if ind2<0: return ind1+1
            if s1[ind1]==s2[ind2]:
                return editDistanceUtil(ind1-1,ind2-1)
            return 1+min(editDistanceUtil(ind1-1,ind2-1),editDistanceUtil(ind1,ind2-1),editDistanceUtil(ind1-1,ind2))
        return  editDistanceUtil(len(s1)-1,len(s2)-1)
            
            