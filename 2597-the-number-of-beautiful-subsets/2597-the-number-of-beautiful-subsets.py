class Solution:
    ans=[]
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        nums.sort()

        def recur(ind):
            if ind>=len(nums):
                return 0
            
            # pick
            op1=0
            if len(self.ans)==0 or nums[ind]-k not in self.ans:
                temp=nums[ind]                
                self.ans.append(temp)
                op1=1+recur(ind+1)
                
                # backtrack
                self.ans.remove(temp)
            # notpick
            op2=recur(ind+1)
            
            return op1+op2
        
        return recur(0)