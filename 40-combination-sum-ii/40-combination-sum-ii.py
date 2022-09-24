class Solution:
    
    def findCombination(self,ind,target,arr,ans,ds):
        if target==0:
            if ds not in ans:
                # print(type(list(ds)))
                ans.append(list(ds))
            # print(ans)
            return 
        for i in range(ind,len(arr)):
            if i>ind and arr[i]==arr[i-1]:
                continue
            if arr[i]>target:
                break
            ds.append(arr[i])
            self.findCombination(i+1,target-arr[i],arr,ans,ds)
            ds.pop()
                
            
        
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ds=[]
        ans=[]
        self.findCombination(0,target,candidates,ans,ds)
        return list(ans)