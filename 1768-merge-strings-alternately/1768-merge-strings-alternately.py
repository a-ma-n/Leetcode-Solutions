class Solution:
    def mergeAlternately(self, w1: str, w2: str) -> str:
        # =min(len(w1),len(w2))
        if len(w1)<len(w2):
            minL=len(w1)
            long=w2[minL:]
        else:
            minL=len(w2)
            long=w1[minL:]
        ans=""
        i=0
        while i<minL:
                ans+=w1[i]+w2[i]
                i+=1
        return ans+long
        
            