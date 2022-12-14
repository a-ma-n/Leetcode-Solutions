class Solution:
    maxAmount=0
    
    def rob(self, nums: List[int]) -> int:
        @cache
        def findAmount(index,profit):
            self.maxAmount=max(self.maxAmount,profit)
            if index<0: return 
            # print(index,profit,nums[index])
            findAmount(index-2,profit+nums[index])
            findAmount(index-1,profit)
        
        findAmount(len(nums)-1,0)
        
        return self.maxAmount