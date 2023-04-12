class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        lo,hi=0,len(s)
        ans=[]
        for i in s:
            if i=='I':
                ans.append(lo)
                lo+=1
            else:
                ans.append(hi)
                hi-=1
        return ans+[lo]