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
        index= dp[l1][l2]
        lcs=""
        ind1,ind2=l1,l2
        while(ind1>0 and ind2>0):
            if text1[ind1-1]==text2[ind2-1]:
                lcs+=text1[ind1-1]
                index-=1
                ind1-=1
                ind2-=1
            elif(dp[ind1-1][ind2]>dp[ind1][ind2-1]):
                lcs+=text1[ind1-1]
                ind1-=1
            else:
                lcs+=text2[ind2-1]
                ind2-=1
        print(ind1-1,ind2-1,lcs)
        while ind1>0:
            lcs+=text1[ind1-1]
            ind1-=1
        while ind2>0:
            lcs+=text2[ind2-1]
            ind2-=1
        return lcs[::-1]
            
                    
                    
            
    
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        return self.longestCommonSubsequence(str1,str2)