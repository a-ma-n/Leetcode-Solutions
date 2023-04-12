class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        res=[]
        target=mean*(len(rolls)+n)-sum(rolls)
        
        if not n<=target<=n*6: return []
        
        part,rem=divmod(target,n)
        
        
        ans=[part]*n
        
        while rem>0:
            rem-=1
            ans[rem]+=1
        return ans
            
        