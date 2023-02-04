from functools import cache

class Solution:
    def isMatch(self, s2: str, s1: str) -> bool:
        def isAllStars(r,idx):
            for i in range(1,idx+1):
                if r[i-1]!='*':
                    return False
            return True
        prev=[False]*(len(s2)+1)
        cur=[False]*(len(s2)+1)
        # dp=[[False]*(len(s2)+1) for i in range(len(s1)+1)]
        prev[0]=True
        # for i in range(1,len(s2)+1): dp[0][i]=False
        # for i in range(1,len(s1)+1): dp[i][0]=isAllStars(s1,i)
        
        for ind1 in range(1,len(s1)+1):
            cur[0]=isAllStars(s1,ind1)
            for ind2 in range(1,len(s2)+1):
                if s1[ind1-1]==s2[ind2-1] or s1[ind1-1]=='?':
                    cur[ind2]=prev[ind2-1]
                else:
                    if s1[ind1-1]=='*':
                        cur[ind2]= prev[ind2] or cur[ind2-1]
                    else:
                        cur[ind2]= False
            prev=cur.copy()
        return prev[len(s2)]
         