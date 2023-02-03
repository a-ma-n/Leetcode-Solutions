from functools import cache
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1,l2=len(text1),len(text2)
        # shifting of indexes -1 is at 0
        dp=[[0]*(l2+1) for i in range(l1+1)]
        for i in range(l1): dp[i][0]=0
        for i in range(l2): dp[0][i]=0
        for ind1 in range(1,l1+1):
            for ind2 in range(1,l2+1):
                if text1[ind1-1]==text2[ind2-1]:
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1]
                else:
                    dp[ind1][ind2]=max(dp[ind1][ind2-1],dp[ind1-1][ind2])
        return dp[l1][l2]
    
        # @cache
        # def lcs(ind1,ind2):
        #     if ind1<0 or ind2<0: return 0
        #     if text1[ind1]==text2[ind2]:
        #         return 1+lcs(ind1-1,ind2-1)
        #     return max(lcs(ind1-1,ind2),lcs(ind1,ind2-1))
        # return lcs(len(text1)-1,len(text2)-1)