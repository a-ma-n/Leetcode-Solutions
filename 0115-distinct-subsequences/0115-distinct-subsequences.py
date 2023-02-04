from functools import cache
class Solution:
    def numDistinct(self, s1: str, s2: str) -> int:
        l1,l2=len(s1),len(s2)
        
        prev=[0]*(l2+1)
        cur=[0]*(l2+1)
        # dp=[[0]*(l2+1) for i in range(l1+1)]
        prev[0]=1
        # for j in range(1,l2+1): dp[0][j]=0 # leave the 1 in the row itself, if say bith are -1 then take 1
            
        for ind1 in range(1,l1+1):
            for ind2 in range(l2,0,-1):
                
                if s1[ind1-1]==s2[ind2-1]:
                    leaveOne=prev[ind2-1]
                    stay=prev[ind2]
                    prev[ind2]=leaveOne+stay
                else:
                    prev[ind2]=prev[ind2]
            # prev=cur
        return prev[l2]
    
       
            