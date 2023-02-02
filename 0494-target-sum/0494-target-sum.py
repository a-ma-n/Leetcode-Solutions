# https://takeuforward.org/data-structure/target-sum-dp-21/
from functools import cache
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        totSum=sum(nums)
        if (totSum-target)%2==1: return 0
        if totSum<target: return 0
        tar=(totSum-target)//2
        # tar=s2
        mod=int(1e9+7)
        n=len(nums)
        dp=[[0]*(tar+1) for i in range(n)]
        
        if nums[0]==0: dp[0][0]=2
        else: dp[0][0]=1
            
        if nums[0]<=tar and nums[0]!=0: dp[0][nums[0]]=1
            
        for ind in range(1,len(nums)):
            for t in range(tar+1):
                notTaken=dp[ind-1][t]
                taken=0
                if nums[ind]<=t:
                    taken=dp[ind-1][t-nums[ind]]
                dp[ind][t]=(taken+notTaken)%mod
        return dp[len(nums) -1][tar]