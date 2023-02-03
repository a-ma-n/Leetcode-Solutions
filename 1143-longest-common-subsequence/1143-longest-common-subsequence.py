from functools import cache
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1,l2=len(text1),len(text2)
        # shifting of indexes -1 is at 0
        k=max(l1,l2)
        prev=[0]*(l2+1)
        cur=[0]*(l2+1)
        for ind1 in range(1,l1+1):
            for ind2 in range(1,l2+1):
                if text1[ind1-1]==text2[ind2-1]:
                    cur[ind2]=1+prev[ind2-1]
                else:
                    cur[ind2]=max(cur[ind2-1],prev [ind2])
            prev = cur.copy()
        
        return prev[l2]
    