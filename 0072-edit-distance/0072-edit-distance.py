from functools import cache
class Solution:
    def minDistance(self, s1: str, s2: str) -> int:
        l1,l2=len(s1),len(s2)
        dp=[[0]*(l2+1) for i in range(l1+1)]
        for i in range(l1+1): 
            dp[i][0]=i
        for i in range(l2+1): 
            dp[0][i]=i
        for ind1 in range(1,l1+1):
            for ind2 in range(1,l2+1):
                if s1[ind1-1]==s2[ind2-1]:
                    dp[ind1][ind2]= dp[ind1-1][ind2-1]
                else:
                    dp[ind1][ind2]= 1+min(dp[ind1-1][ind2-1],dp[ind1][ind2-1],dp[ind1-1][ind2])
            
        return  dp[l1][l2]
        # @cache
        # def editDistanceUtil(ind1,ind2):
        #     if ind1<0: return ind2+1
        #     if ind2<0: return ind1+1
        #     if s1[ind1]==s2[ind2]:
        #         return editDistanceUtil(ind1-1,ind2-1)
        #     return 1+min(editDistanceUtil(ind1-1,ind2-1),editDistanceUtil(ind1,ind2-1),editDistanceUtil(ind1-1,ind2))
        # return  editDistanceUtil(len(s1)-1,len(s2)-1)
            
            