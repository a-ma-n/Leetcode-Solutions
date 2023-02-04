from functools import cache
class Solution:
    def minDistance(self, s1: str, s2: str) -> int:
        l1,l2=len(s1),len(s2)
        # if l2>l1:
        #     s1,s2=s2,s1
        #     l1,l2=l2,l1
            
        prev=[0]*(l2+1)
        cur=[0]*(l2+1)
        for j in range(l2+1): 
            prev[j]=j
        
        for ind1 in range(1,l1+1):
            cur[0]=ind1
            for ind2 in range(1,l2+1):
                if s1[ind1-1]==s2[ind2-1]:
                    cur[ind2]= prev[ind2-1]
                else:
                    cur[ind2]= 1+min(prev[ind2-1],cur[ind2-1],prev[ind2])
            prev=cur.copy()
            
        return  prev[l2]
      
            