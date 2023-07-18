class Solution:
    def combinationSum(self, c: List[int], target: int) -> List[List[int]]:
        N=len(c)
        def recur(ind,t,combn):
            # if t<0: return
            if ind==N: 
                if t==0:
                    self.combinations.append(combn.copy())
                return 
            # pick
            # if c[ind]<target:
            if c[ind]<=t:
                combn.append(c[ind])
                recur(ind,t-c[ind],combn)
                combn.pop()
            recur(ind+1,t,combn)
        self.combinations=[]
        recur(0,target,[])
        return self.combinations
            