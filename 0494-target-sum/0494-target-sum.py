from functools import cache
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total=sum(nums)
        dp=[[0]*(2*total+1) for i in range(len(nums))]
        # base cases
        dp[0][nums[0]+total]=1
        dp[0][-nums[0]+total]+=1
        
        for i in range(1,len(nums)):
            for sumVal in range(-total,total+1):
                if dp[i-1][sumVal+total]>0:
                    dp[i][sumVal+nums[i]+total]+=dp[i-1][sumVal+total]
                    dp[i][sumVal-nums[i]+total]+=dp[i-1][sumVal+total]
        if abs(target)>total:
            return 0
        else:
            return dp[len(nums)-1][target+total]
        # @cache
        # def findWays(ind,target):
        #     if ind<0:
        #         if target==0:
        #             return 1
        #         return 0
        #     subtract=findWays(ind-1,target+nums[ind])
        #     add=findWays(ind-1,target-nums[ind])
        #     return add+subtract
        # return findWays(len(nums)-1,target)